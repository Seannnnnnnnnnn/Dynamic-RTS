#pragma once

#include "../DTAlgorithm.h"

// extends the basic DT Algorithm class with a number of methods for testing 

class TestDTAlgorithmClass : DTAlgorithm {

public:
    using DTAlgorithm::DTAlgorithm;
    
    std::vector<Query>& getQuerySet();
    std::vector<TreeNode*> getNodes();
    std::vector<DistributedTracking*> getDTInstancesFromNodes();
};