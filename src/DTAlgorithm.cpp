#include "DTAlgorithm.h"

DTAlgorithm::DTAlgorithm(const std::vector<Query>& queries)
    : EndpointTree(queries) {
    // also find canonical node set for each query and set associated dtInstances for each node
    for (auto query : queries) {
        std::vector<TreeNode*> canonicalNodes = findCanonicalNodeSet(query);
        DistributedTracking dtInstance(query, canonicalNodes);
        dtInstances.push_back(dtInstance);
        
        for (TreeNode* node : canonicalNodes) {
            node->dtInstances.push_back(dtInstance);
        }
    }
}

void DTAlgorithm::processElement(const StreamElement& streamElement) {
    // overrides the element processing of the EndpointTree class, as we now use 
    // the dtInstances to manage query maturation 
    TreeNode* current = getRoot().get();
    int value  = streamElement.value;
    int weight = streamElement.weight;
    
    if (value < minimum_endpoint || value > maximum_endpoint) { return; }  // don't process if it's not in the tree

    while (current->left && current->right) {
        current->incrementCounter(weight);
        manageCounterUpdate(current, weight);  
        TreeNode* left = current->left.get();
        if (left->stabsJurisdictionInterval(value)){
            current = left;
        } else {
            current = current->right.get();
        }
    }
    return;
}


void manageCounterUpdate(TreeNode* treeNode, int increment) {
    // called upon counter updates - responsible for managing communication for DT
    // TODO: update to use heaps
    
    // Alg: for each DT instance which has treeNode in their participant set, update signal with new counter 
    for (auto& dtInstance : treeNode->dtInstances) {
        if (dtInstance.isAlive()) {
            dtInstance.processCounterIncrement(increment);  // TODO: finalise 
        } 
    }
    return;
}