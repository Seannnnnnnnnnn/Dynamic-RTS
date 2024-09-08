#pragma once
#include <memory>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include "DistributedTracking.h"

using DTHeapEntry = std::pair<int, DistributedTracking*>;  // (key, dtInstance)
using DTInstancePair = std::pair<int, DistributedTracking*>;
using DTHeap = std::priority_queue<DTInstancePair, std::vector<DTInstancePair>, std::greater<>>;

struct CompareHeapEntry {
        bool operator()(const DTHeapEntry& lhs, const DTHeapEntry& rhs) const {
            return lhs.first > rhs.first;  // Min-heap comparator
        }
    };


// Add a structure to store the counter and slack value
struct DTInstanceData {
    int lastNodeCounter;
    int slack;
};


struct TreeNode {
    int counter;
    int endpoint;
    int jurisdictionLeft;
    int jurisdictionRight;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode() : 
        endpoint(0), jurisdictionLeft(0), jurisdictionRight(0), 
        left(nullptr), right(nullptr), counter(0) {}

    int getCounter() { return counter; }
    inline bool stabsJurisdictionInterval(int value) { return jurisdictionLeft <= value < jurisdictionRight; }
    inline void incrementCounter(int weight) { counter += weight; }

    // Distributed Tracking methods and attributes
    DTHeap dtHeap;    
    std::unordered_map<DistributedTracking*, std::pair<int, int>> dtInstanceDataMap; // <dtInstance, <last_signal_counter, slack>>
    
    void initializeDTInstanceData(DistributedTracking* dtInstance);
    void updateSlack(DistributedTracking* dtInstance, int newSlack);
    void initialiseHeap();
};
