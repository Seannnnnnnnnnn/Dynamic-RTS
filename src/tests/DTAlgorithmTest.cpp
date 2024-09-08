#include <queue>
#include "DTAlgorithmTest.h"


std::vector<TreeNode*> TestDTAlgorithmClass::getNodes(){
    
    std::vector<TreeNode*> allNodes;
    std::unique_ptr<TreeNode>& rootPtr = getRoot();

    if (rootPtr != nullptr){
        
        TreeNode* root = rootPtr.get();
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Add current node to the list of all nodes
            allNodes.push_back(currentNode);
            
            if (currentNode->left){
                nodeQueue.push(currentNode->left.get());
            }
            if (currentNode->right){
                nodeQueue.push(currentNode->right.get());
            }
        }
    }
    return allNodes;
}


std::vector<DistributedTracking*> TestDTAlgorithmClass::getDTInstances(){
    return dtInstances;
}


std::vector<DistributedTracking*> TestDTAlgorithmClass::getDTInstancesFromNodes(){
    
    std::vector<DistributedTracking*> dtInstances;
    std::vector<TreeNode*> allNodes = getNodes();
    
    for (auto node : allNodes){
        // get all the keys in the nodes DTInstance Map

        std::vector<DistributedTracking*> nodeDtInstances;
        nodeDtInstances.reserve(node->dtInstanceDataMap.size());
        
        for (auto kv : node->dtInstanceDataMap) {
            nodeDtInstances.push_back(kv.first);
        }
        
        dtInstances.insert(dtInstances.end(), nodeDtInstances.begin(), nodeDtInstances.end());
    }
    return dtInstances;
}