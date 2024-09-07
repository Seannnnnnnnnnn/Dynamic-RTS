#pragma once
#include <memory>
#include <vector>
#include "DistributedTracking.h"


struct TreeNode {
    int counter;
    int endpoint;
    int jurisdictionLeft;
    int jurisdictionRight;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    int last_signal_counter;  // used for distributed tracking

    // TODO: change below to a set
    std::vector<DistributedTracking> dtInstances; // list of DT instances that have this node in it's participant set

    TreeNode() : 
        endpoint(0), jurisdictionLeft(0), jurisdictionRight(0), 
        left(nullptr), right(nullptr), counter(0) {}

    int getCounter() { return counter; }
    inline bool stabsJurisdictionInterval(int value) { return jurisdictionLeft <= value <= jurisdictionRight; }
    inline void incrementCounter(int weight) { counter += weight; }
    inline int getLastSignalCounter() const { return last_signal_counter; }
    inline void setLastSignalCounter(int new_value ) { last_signal_counter = new_value; }
};
