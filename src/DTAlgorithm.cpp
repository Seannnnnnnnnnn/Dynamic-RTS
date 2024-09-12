#include "DTAlgorithm.h"


DTAlgorithm::DTAlgorithm(std::vector<Query>& queries): 
    EndpointTree(queries), querySet(queries) {
        // Build the Endpoint Tree and DT instances for registered queries
        for (auto& query : queries) {  // Use auto& to avoid making a copy
            std::vector<TreeNode*> canonicalNodes = findCanonicalNodeSet(query);
            
            auto dtInstance = std::make_unique<DistributedTracking>(query, canonicalNodes);
            dtInstances.push_back(std::move(dtInstance));
            DistributedTracking* dtInstancePtr = dtInstances.back().get();
            
            for (TreeNode* node : canonicalNodes) {
                // Initialize with last signal counter = 0
                node->dtInstanceList.push_back(dtInstancePtr);
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

    while (current) {
        TreeNode* left = current->left.get();
        TreeNode* right = current->right.get();
        
        current->counter+=weight;
        manageCounterUpdate(current);  
        
        if (left && left->stabsJurisdictionInterval(value)) {
            current = left;
        } else {
            current = right;
        }
    }
}


void DTAlgorithm::manageCounterUpdate(TreeNode* treeNode) {
    while(!treeNode->dtHeap.empty()){

        auto [minimumKey, dtInstance] = treeNode->dtHeap.top();

        if (treeNode->counter < minimumKey){
            break;
        }
        
        treeNode->dtHeap.pop();  
        int slack = dtInstance->getSlack();
        int previousCounterValue = treeNode->dtInstanceDataMap[dtInstance].first;

        // for handling non-uniform counter increases - see section 7 of paper
        while (treeNode->counter - previousCounterValue >= slack){
            dtInstance->processSignal(slack); 
            previousCounterValue += slack;
        }

        // only perform the following if the dt instance is still alive after processing the latest counter change: 
        if (dtInstance->isAlive()) {
            int newSlack = dtInstance->getSlack();
            // if the slack doesn't change we need to update heap key
            // the else-case is handled by the DistributedTracking
            int newKey = newSlack + previousCounterValue;
            treeNode->dtInstanceDataMap[dtInstance] = {previousCounterValue, newSlack};
            treeNode->dtHeap.push({newKey, dtInstance});
        }
    }
}


std::vector<Query>& DTAlgorithm::getQuerySet() {
    return querySet;
}


TreeNode* DTAlgorithm::getDTRoot() {
    return getRoot().get();
}
