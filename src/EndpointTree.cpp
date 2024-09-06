#include "EndpointTree.h"
#include <algorithm>
#include <set>
#include <vector>

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
        node->endpoint = endpoints[left];
        node->jurisdictionLeft = endpoints[left];
        node->jurisdictionRight = (left + 1 < endpoints.size()) ? endpoints[left + 1] : INFTY;
        return;
    }

    int mid = left + (right - left) / 2;
    node->endpoint = endpoints[mid];
    
    node->left = std::make_unique<TreeNode>();
    node->right = std::make_unique<TreeNode>();
    
    buildTree(node->left, left, mid);
    buildTree(node->right, mid + 1, right);

    node->jurisdictionLeft = node->left->jurisdictionLeft;
    node->jurisdictionRight = node->right->jurisdictionRight;
}

TreeNode* EndpointTree::findLeaf(int value, TreeNode* node) const {
    if (!node) return nullptr;
    if (node->endpoint == value) return node;
    if (value < node->endpoint) return findLeaf(value, node->left.get());
    else return findLeaf(value, node->right.get());
}

TreeNode* EndpointTree::findLCA(TreeNode* node, TreeNode* p, TreeNode* q) const {
    if (!node || node == p || node == q) return node;
    TreeNode* left = findLCA(node->left.get(), p, q);
    TreeNode* right = findLCA(node->right.get(), p, q);
    if (left && right) return node;
    return left ? left : right;
}

void EndpointTree::addNodes(TreeNode* node, const Query& query, std::vector<TreeNode*>& result) const {
    if (!node) return;
    
    if (node->jurisdictionLeft >= query.r || node->jurisdictionRight <= query.l) {
        // No overlap
        return;
    }
    
    if (node->jurisdictionLeft >= query.l && node->jurisdictionRight <= query.r) {
        // Interval of node is within query interval
        result.push_back(node);
        return;
    }
    
    // Recursively add nodes from children
    addNodes(node->left.get(), query, result);
    addNodes(node->right.get(), query, result);
}

std::vector<TreeNode*> EndpointTree::findCanonicalNodeSet(const Query& query) const {
    std::vector<TreeNode*> result;
    
    TreeNode* leafX = findLeaf(query.l, root.get());
    TreeNode* leafY = findLeaf(query.r, root.get());
    
    if (leafX && leafY) {
        TreeNode* lca = findLCA(root.get(), leafX, leafY);
        addNodes(lca, query, result);
    }
    
    return result;
}

void EndpointTree::processElement(const StreamElement& element) const {
    TreeNode* current = root.get();
    int value  = element.value;
    int weight = element.weight;
    
    while (current) {
        // TODO: update counter in current node
        TreeNode* left = current->left.get();

        if (left->stabsJurisdictionInterval(value)){
            current = left;
        } else {
            current = current->right.get();
        }
    }
}
