#include "DistributedTracking.h"
#include "TreeNode.h"


DistributedTracking::DistributedTracking(Query& coordinator, std::vector<TreeNode*>& participants)
    : coordinator(coordinator), participants(participants), threshold(coordinator.getThreshold()), 
      numSignalsReceived(0) 
      { 
        calculateAndSetSlack();
      }


int DistributedTracking::calculateAndSetSlack() {
    int h = participants.size();
    if (threshold <= 6 * h) {
        slack = 1;
    } else {
        slack = threshold / (2 * h);
    }
    return slack;
}


std::vector<TreeNode*> DistributedTracking::getParticipants(){
    return participants;
}


bool DistributedTracking::isAlive() const {
    return coordinator.alive;
}


int DistributedTracking::getSlack() const {
    return slack;
}


int DistributedTracking::getThreshold() const {
    return threshold;
}


void DistributedTracking::processSignal(int counterChange){
    // counterChange: difference between node counter now and counter at last signal sent

    if (slack == 1){  // in the straight forward solution, we process all signals we receive
        threshold -= counterChange;
        if (threshold <= 0) { processMaturity(); }
    }

    else {
        numSignalsReceived++;
        int h = participants.size();
        // if we receive h messages, collect counters and rebuild with new slack
        if (numSignalsReceived % h == 0){
            // get counters from all participants 
            int totalCounters = 0;
            for (auto participant : participants) {
                totalCounters += participant->counter;
            }
            threshold -= totalCounters;

            if (threshold <= 0) {
                processMaturity();
            }

            int new_slack = calculateAndSetSlack();

            for (auto participant : participants) {
                participant->updateSlack(this, new_slack);
            }
        }
    } 
}

void DistributedTracking::processMaturity() {
    // Mark the query as matured
    coordinator.alive = false;

    for (auto participant : participants) {
        auto it = participant->dtInstanceDataMap.find(this);
        if (it != participant->dtInstanceDataMap.end()) {
            // Remove slack value associated with this DT instance.
            participant->dtInstanceDataMap.erase(it);  // Remove the instance directly
        }
        // Rebuild the heap since the DT instance has been removed and slack values changed.
        if (!participant->dtHeap.empty()){
            participant->initialiseHeap();
        }
    }
    return;
}
