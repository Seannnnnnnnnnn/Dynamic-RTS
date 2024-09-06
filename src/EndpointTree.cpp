#include "EndpointTree.h"
#include <algorithm>
#include <set>

EndpointTree::EndpointTree(const std::vector<Query>& queries) {
    std::set<int> uniqueEndpoints;
    for (const auto& query : queries) {
        uniqueEndpoints.insert(query.l);
        uniqueEndpoints.insert(query.r);
    }
    endpoints.assign(uniqueEndpoints.begin(), uniqueEndpoints.end());
    root = std::make_unique<TreeNode>();
    buildTree(root, 0, endpoints.size() - 1);
}

std::unique_ptr<TreeNode>& EndpointTree::getRoot() {
    return root;
}

void EndpointTree::buildTree(std::unique_ptr<TreeNode>& node, int left, int right) {
    if (left == right) {
        // Leaf node
        node->endpoint = endpoints[left];
        node->jurisdictionLeft = endpoints[left];
        node->jurisdictionRight = (left + 1 < endpoints.size()) ? endpoints[left + 1] : INFTY;
        return;
    }

    int mid = left + (right - left) / 2;
    node->endpoint = endpoints[mid];
    
    // Recursively build left and right subtrees
    node->left = std::make_unique<TreeNode>();
    node->right = std::make_unique<TreeNode>();
    
    buildTree(node->left, left, mid);
    buildTree(node->right, mid + 1, right);

    // Set jurisdiction interval for the current node
    node->jurisdictionLeft = node->left->jurisdictionLeft;
    node->jurisdictionRight = node->right->jurisdictionRight;
}
