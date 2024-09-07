#include "DistributedTracking.h"
#include "TreeNode.h"

DistributedTracking::DistributedTracking(const Query& coordinator, std::vector<TreeNode*>& participants)
    : coordinator(coordinator), participants(participants) {
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


bool DistributedTracking::isAlive() const {
    return coordinator.getThreshold() <= 0;
}


void DistributedTracking::processCounterIncrement(const int increment) {
    // TODO: 
    return;
}
