#include "TreeNode.h"
#include <iostream>

void TreeNode::initializeDTInstanceData(DistributedTracking* dtInstance) {
    dtInstanceDataMap[dtInstance] = {0, 0};  // Initialize with default values
}


void TreeNode::updateSlack(DistributedTracking* dtInstance, int newSlack){
    auto it = dtInstanceDataMap.find(dtInstance);
    if (it != dtInstanceDataMap.end()) {
        it->second.second = newSlack; 
        // Rebuild the heap since slack has changed
        initialiseHeap();
    }
}


void TreeNode::initialiseHeap() {
    // Clear the existing heap
    while (!dtHeap.empty()) {
        dtHeap.pop();
    }

    // Populate the heap with the current dtInstances
    for (const auto& [dtInstance, data] : dtInstanceDataMap) {
        int key = data.first + data.second; // last_signal_counter + slack
        dtHeap.emplace(key, dtInstance);
    }
}