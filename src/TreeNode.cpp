#include "TreeNode.h"

void TreeNode::initialiseHeap(){
    // Clear the existing heap
    while (!dtHeap.empty()) {
        dtHeap.pop();
    }

    // Populate the heap with the current dtInstances
    for (auto& dtInstance : dtInstances) {
        int key = dtInstance->getSlack() + last_signal_counter;
        dtHeap.emplace(key, dtInstance);
    }
}