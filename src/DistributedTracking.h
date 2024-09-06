#pragma once

#include <vector>
#include "Query.h"
#include "TreeNode.h"
#include "StreamElement.h"


class DistributedTracking {
public:
    DistributedTracking(Query& coordinator, std::vector<TreeNode*>& participants);

    void processElement(const StreamElement& element);
    bool isThresholdMet() const;

private:
    Query& coordinator;
    std::vector<TreeNode*> participants;
    int slack;
    int numSignalsReceived;
    int totalCounter;

    void calculateSlack();
    void updateSignals();
};
