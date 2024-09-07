#pragma once

#include <vector>
#include "Query.h"
#include "StreamElement.h"

struct TreeNode;  // forward decleration to avoid circular dependancy

class DistributedTracking {
public:
    DistributedTracking(const Query& coordinator, std::vector<TreeNode*>& participants);
    void processCounterIncrement(const int increment);
    bool isAlive() const;  // flag for if the DistributedTracking instance is still alive

private:
    const Query& coordinator;
    std::vector<TreeNode*> participants;
    int slack;
    int numSignalsReceived;
    int totalCounter;

    void calculateSlack();
};
