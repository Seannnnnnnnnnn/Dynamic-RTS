#ifndef ENDPOINTTREE_H
#define ENDPOINTTREE_H

#include <vector>
#include <memory>
#include <limits>
#include "Query.h"

static constexpr int INFTY = std::numeric_limits<int>::max();

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
    std::vector<TreeNode*> findCanonicalNodeSet(const Query& query) const;

private:
    std::vector<int> endpoints;
    std::unique_ptr<TreeNode> root;

    void buildTree(std::unique_ptr<TreeNode>& node, int left, int right);
    TreeNode* findLeaf(int value, TreeNode* node) const;
    TreeNode* findLCA(TreeNode* node, TreeNode* p, TreeNode* q) const;
    void addNodes(TreeNode* node, const Query& query, std::vector<TreeNode*>& result) const;
};

#endif // ENDPOINTTREE_H
