#include "DistributedTracking.h"

DistributedTracking::DistributedTracking(Query& coordinator, std::vector<TreeNode*>& participants)
    : coordinator(coordinator), participants(participants), numSignalsReceived(0), totalCounter(0) {
    calculateSlack();
}

void DistributedTracking::calculateSlack() {
    int h = participants.size();
    int T = coordinator.getThreshold();
    if (T <= 6 * h) {
        slack = 1;  // Straightforward solution
    } else {
        slack = T / (2 * h);
    }
}

void DistributedTracking::processElement(const StreamElement& element) {
    for (auto& participant : participants) {
        if (participant->stabsJurisdictionInterval(element.value)) {
            participant->incrementCounter(element.weight);

            // Check if we need to send a signal based on the slack value
            if (participant->getCounter() >= participant->getLastSignalCounter() + slack) {
                numSignalsReceived++;
                participant->getLastSignalCounter();
            }
        }
    }
    updateSignals();
}

void DistributedTracking::updateSignals() {
    if (numSignalsReceived >= participants.size()) {
        // All participants have sent their signals, check total counter
        totalCounter = 0;
        for (auto& participant : participants) {
            totalCounter += participant->getCounter();
        }
        numSignalsReceived = 0;  // Reset for next round
        coordinator.updateThreshold(coordinator.getThreshold() - totalCounter);
        calculateSlack();  // Recalculate slack for next round
    }
}

bool DistributedTracking::isThresholdMet() const {
    return coordinator.getThreshold() <= 0;
}
