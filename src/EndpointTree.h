#pragma once

#include <vector>
#include <memory>
#include <limits>
#include "TreeNode.h"
#include "Query.h"
#include "StreamElement.h"

static constexpr int INFTY = std::numeric_limits<int>::max();

class EndpointTree {
public:
    int minimum_endpoint; 
    int maximum_endpoint;
    
    explicit EndpointTree(std::vector<Query>& queries);
    std::unique_ptr<TreeNode>& getRoot();
    std::vector<TreeNode*> findCanonicalNodeSet(const Query& query) const;
    int processElement(const StreamElement& element);

protected:
    TreeNode* getRoot() const;

private:
    std::vector<int> endpoints;
    std::unique_ptr<TreeNode> root;

    void buildTree(std::unique_ptr<TreeNode>& node, int left, int right);
    TreeNode* findLeaf(int value, TreeNode* node) const;
    TreeNode* findLCA(TreeNode* node, TreeNode* p, TreeNode* q) const;
    void addNodes(TreeNode* node, const Query& query, std::vector<TreeNode*>& result) const;
};
