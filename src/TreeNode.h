#pragma once
#include <memory>


struct TreeNode {
    int counter;
    int last_signal_counter;  // used for distributed tracking
    int endpoint;
    int jurisdictionLeft;
    int jurisdictionRight;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode() : endpoint(0), jurisdictionLeft(0), jurisdictionRight(0), left(nullptr), right(nullptr), counter(0) {}

    bool stabsJurisdictionInterval(int value);
    void incrementCounter(int weight);
    int getCounter() { return counter; }
    inline int getLastSignalCounter() const { return last_signal_counter; }
    inline void setLastSignalCounter(int new_value ) { last_signal_counter = new_value; }
};
