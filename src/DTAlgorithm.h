#pragma once

#include "EndpointTree.h"
#include "DistributedTracking.h"

class DTAlgorithm : public EndpointTree {
public:
    DTAlgorithm(std::vector<Query>& queries);
    void processElement(const StreamElement& element);
    std::vector<Query>& getQuerySet();

private:
    std::vector<Query>& querySet;
    std::vector<DistributedTracking*> dtInstances;
    void manageCounterUpdate(TreeNode* node);
};

