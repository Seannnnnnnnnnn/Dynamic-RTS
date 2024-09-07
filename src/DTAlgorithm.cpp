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
            node->dtInstances.push_back(dtInstancePtr);
            node->dtSlacks.push_back(dtInstancePtr->getSlack()); 
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
    while(!treeNode->dtHeap.empty()){

        int minKey = treeNode->dtHeap.top().first;

        if (treeNode->counter < minKey){
            break;
        }
        
        auto minPair = treeNode->dtHeap.top();
        treeNode->dtHeap.pop();

        DistributedTracking* dtInstance = minPair.second;
        int slack = dtInstance->getSlack();

        auto newEnd = std::remove(treeNode->dtSlacks.begin(), treeNode->dtSlacks.end(), slack);
        treeNode->dtSlacks.erase(newEnd, treeNode->dtSlacks.end());
        dtInstance->processSignal();

        // After processing, push the updated slack value into the heap if still alive
        if (dtInstance->isAlive()){
            int newKey = dtInstance->getSlack() + treeNode->last_signal_counter;
            treeNode->dtHeap.emplace(newKey, dtInstance);
        }
    }
}


std::vector<Query>& DTAlgorithm::getQuerySet() {
    return querySet;
}