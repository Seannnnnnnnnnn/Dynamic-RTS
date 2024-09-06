#pragma once
#include <memory>


class TreeNode {
public:
    int counter;
    int endpoint;
    int jurisdictionLeft;
    int jurisdictionRight;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode() : endpoint(0), jurisdictionLeft(0), jurisdictionRight(0), left(nullptr), right(nullptr), counter(0) {}

    bool stabsJurisdictionInterval(int value);
    void incrementCounter(int weight);
};



