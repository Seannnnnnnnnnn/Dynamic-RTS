#pragma once

#include "EndpointTree.h"
#include "DistributedTracking.h"

class DTAlgorithm : public EndpointTree {
public:
    DTAlgorithm(const std::vector<Query>& queries);
    void processElement(const StreamElement& element);

private:
    std::vector<DistributedTracking> dtInstances;
    void manageCounterUpdate(TreeNode* node, int increment);  // for managing after counter increments
};

