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
            // initialise with last signal counter = 0
            node->dtInstanceDataMap[dtInstancePtr] = {0, dtInstancePtr->getSlack()};
            node->initialiseHeap();
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
    // TODO: may need to update the logic here
    while(!treeNode->dtHeap.empty()){

        auto [minimumKey, dtInstance] = treeNode->dtHeap.top();
        
        // Retrieve the specific last counter and slack for this DT instance
        auto& instanceData = treeNode->dtInstanceDataMap[dtInstance];

        if (treeNode->counter < minimumKey){
            break;
        }

        treeNode->dtHeap.pop();  
        dtInstance->processSignal();

        // Update the new slack value after processing the signal
        int newSlack = dtInstance->getSlack();
        int newKey = newSlack + treeNode->counter;
        treeNode->dtInstanceDataMap[dtInstance] = {treeNode->counter, newSlack};
        treeNode->dtHeap.push({newKey, dtInstance});
    }
}


std::vector<Query>& DTAlgorithm::getQuerySet() {
    return querySet;
}