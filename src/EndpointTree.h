#ifndef ENDPOINTTREE_H
#define ENDPOINTTREE_H

#include <vector>
#include <memory>
#include <limits>
#include "Query.h"

const int INFTY = std::numeric_limits<int>::max(); 

class TreeNode {
public:
    int endpoint;
    int jurisdictionLeft;
    int jurisdictionRight;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode() : endpoint(0), jurisdictionLeft(0), jurisdictionRight(0), left(nullptr), right(nullptr) {}
};

class EndpointTree {
public:
    explicit EndpointTree(const std::vector<Query>& queries);
    std::unique_ptr<TreeNode>& getRoot();

private:
    std::vector<int> endpoints;
    std::unique_ptr<TreeNode> root;

    void buildTree(std::unique_ptr<TreeNode>& node, int left, int right);
};

#endif
