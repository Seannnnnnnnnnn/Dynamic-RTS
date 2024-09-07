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
    // if we receive h messages, rebuild with new slack
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
            participant->processNewSlack(new_slack);
        }
    }
}

void DistributedTracking::processMaturity() {
    // Mark the query as matured.
    coordinator.alive = false;

    for (auto participant : participants) {
        // Remove the current slack associated with this DT instance.
        auto newSlackEnd = std::remove(participant->dtSlacks.begin(), participant->dtSlacks.end(), getSlack());
        participant->dtSlacks.erase(newSlackEnd, participant->dtSlacks.end());

        // Directly use 'this' to remove the DT instance from the participant's dtInstances.
        auto dtInstanceEnd = std::remove(participant->dtInstances.begin(), participant->dtInstances.end(), this);

        if (dtInstanceEnd != participant->dtInstances.end()) {
            participant->dtInstances.erase(dtInstanceEnd, participant->dtInstances.end());
        }
    }
}
