#pragma once

#include "EndpointTree.h"
#include "DistributedTracking.h"

class DTAlgorithm : public EndpointTree {
public:
    DTAlgorithm(std::vector<Query>& queries);
    void processElement(const StreamElement& element);
    std::vector<DistributedTracking*> getDTInstances();
    std::vector<Query>& getQuerySet();

protected:
    std::vector<DistributedTracking*> dtInstances;
    std::vector<Query>& querySet;

private:
    void manageCounterUpdate(TreeNode* node);
};

