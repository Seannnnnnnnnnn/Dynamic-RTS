#include "DTAlgorithm.h"
#include <iostream>


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
    TreeNode* targetNode = current->right.get()->left.get();
    std::cout << "Target Node jurisdiction interval: [" << targetNode->jurisdictionLeft << "," << targetNode->jurisdictionRight << ")\n";

    int value  = streamElement.value;
    int weight = streamElement.weight;
    
    if (value < minimum_endpoint || value > maximum_endpoint) { return; }  // don't process if it's not in the tree

    while (current->left && current->right) {
        current->counter+=weight;
        manageCounterUpdate(current);  
        
        if (current->left->stabsJurisdictionInterval(value)) {
            current = current->left.get();
        } else if (current->right->stabsJurisdictionInterval(value)) {
            current = current->right.get();
        } else {
            std::cerr << "Error: No valid child node stabs the value " << value << std::endl;
            break;
        }
    }
}


void DTAlgorithm::manageCounterUpdate(TreeNode* treeNode) {
    // TODO: logic here is still buggy somewhere - need to keep popping until we are done!
    // std::cout << "Checking node with # dtInstances: " << treeNode->dtInstanceList.size() << std::endl;
    while(!treeNode->dtHeap.empty()){

        auto [minimumKey, dtInstance] = treeNode->dtHeap.top();

        if (treeNode->counter < minimumKey){
            break;
        }
        
        treeNode->dtHeap.pop();  
        int previousCounterValue = treeNode->dtInstanceDataMap[dtInstance].first;
        int counterChange = treeNode->counter - previousCounterValue;

        dtInstance->processSignal(counterChange); 
        
        // only perform the following if the dt instance is still alive after processing the latest counter change: 
        if (dtInstance->isAlive()) {
            int newSlack = dtInstance->getSlack();
            // if the slack doesn't change we need to update heap key
            // the else-case is handled by the DistributedTracking
            int newKey = newSlack + treeNode->counter;
            treeNode->dtInstanceDataMap[dtInstance] = {treeNode->counter, newSlack};
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