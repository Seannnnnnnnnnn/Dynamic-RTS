#include "DTAlgorithm.h"

DTAlgorithm::DTAlgorithm(std::vector<Query>& queries)
    : EndpointTree(queries), querySet(queries) {
    // builds the Endpoint Tree and DT instances for registered queries
    for (auto query : queries) {
        std::vector<TreeNode*> canonicalNodes = findCanonicalNodeSet(query);
        auto dtInstance = std::make_unique<DistributedTracking>(query, canonicalNodes);
        
        // Store raw pointer in the vector
        DistributedTracking* dtInstancePtr = dtInstance.get();
        dtInstances.push_back(dtInstancePtr); 

        for (TreeNode* node : canonicalNodes) {
            node->dtInstances.push_back(dtInstancePtr);  // Store raw pointer to DT instance
            node->dtSlacks.push_back(dtInstancePtr->getSlack());
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
        manageCounterUpdate(current);  
        TreeNode* left = current->left.get();
        if (left->stabsJurisdictionInterval(value)){
            current = left;
        } else {
            current = current->right.get();
        }
    }
    return;
}


void DTAlgorithm::manageCounterUpdate(TreeNode* treeNode) {
    // new algorithm  - use heaps to avoid a linear scan over DT instances each time via the following: 
    
    // maintain a min-heap of dtInstances on each treeNode organised by key: dtInstance->getSlack() + treeNode->last_signal_counter
    // instead of a linear scan do the following: 
    // 1. Find the minimum key in the heap in O(1) time
    // 2. if treeNode->counter < minimum key then we are done
    // 3. otherwise: pop min, and perform the logic in our if statement. repeat from step 1.


    // Alg: for each DT instance which has treeNode in their participant set, update signal with new counter 
    for (auto& dtInstance : treeNode->dtInstances) {
        int slack = dtInstance->getSlack();
        if (dtInstance->isAlive() && slack == 1 || (treeNode->counter - treeNode->last_signal_counter) >= slack) {
            // processSignal will assign a new slack to the node, so remove the current slack associated with it's dt instance
            auto newEnd = std::remove(treeNode->dtSlacks.begin(), treeNode->dtSlacks.end(), slack);
            treeNode->dtSlacks.erase(newEnd, treeNode->dtSlacks.end());
            dtInstance->processSignal();
        } 
    }
    return;
}


std::vector<Query>& DTAlgorithm::getQuerySet() {
    return querySet;
}