#include "DistributedTracking.h"
#include "TreeNode.h"

DistributedTracking::DistributedTracking(Query& coordinator, std::vector<TreeNode*>& participants)
    : coordinator(coordinator), participants(participants), threshold(coordinator.getThreshold()), 
      numSignalsReceived(0) {}

int DistributedTracking::calculateSlack() {
    int h = participants.size();
    if (threshold <= 6 * h) {
        slack = 1;  // Straightforward solution
    } else {
        slack = threshold / (2 * h);
    }
    return slack;
}


bool DistributedTracking::isAlive() const {
    return coordinator.alive;
}


int DistributedTracking::getSlack() const {
    return slack;
}


void DistributedTracking::processSignal(){
    numSignalsReceived++;
    int h = participants.size();
    // if we receive h messages, collect counters and rebuild with new slack
    if (numSignalsReceived % h == 0){
        // get counters from all participants 
        int total_counters = 0;
        for (auto participant : participants) {
            total_counters += participant->counter;
        }
        threshold -= total_counters;

        if (threshold <= 0) {
            processMaturity();
            return;
        }

        int new_slack = calculateSlack();

        // assign new slack to each participant
        for (auto participant : participants) {
            participant->updateSlack(this, new_slack);
        }
    }
}

void DistributedTracking::processMaturity() {
    // Mark the query as matured.
    coordinator.alive = false;

    for (auto participant : participants) {
        // Remove the current slack associated with this DT instance from the participant's map.
        auto it = participant->dtInstanceDataMap.find(this);
        if (it != participant->dtInstanceDataMap.end()) {
            // Remove slack value associated with this DT instance.
            int slack = it->second.second;
            auto slackIt = std::find_if(
                participant->dtInstanceDataMap.begin(),
                participant->dtInstanceDataMap.end(),
                [slack](const auto& pair) { return pair.second.second == slack; });

            if (slackIt != participant->dtInstanceDataMap.end()) {
                participant->dtInstanceDataMap.erase(slackIt);
            }

            // Remove the DT instance from the map.
            participant->dtInstanceDataMap.erase(it);
        }

        // Rebuild the heap since the DT instance has been removed and slack values changed.
        participant->initialiseHeap();
    }
}
