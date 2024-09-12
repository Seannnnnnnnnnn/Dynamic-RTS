#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory>
#include <limits>


int INFTY = std::numeric_limits<int>::max();


struct Query{
    int l;  // left endpoint
    int r;  // right endpoint
    int tau;  
    int count = 0; 
    bool alive = true;  

    Query(int l, int r, int tau) : l(l), r(r), tau(tau), alive(true) {}
    inline bool isValid() const {return l < r;}
    inline int getLeft() const {return l;}
    inline int getRight() const {return r;}
    inline bool stabsInterval(int value) {return l <= value <= r;}
    inline void updateCount(int weight) {
        if (alive) {
            count += weight;
            if (count >= tau) {
                alive = false;
            }
        }
    }
};


struct TreeNode {
    int endpoint; 
    std::unique_ptr<TreeNode> left; 
    std::unique_ptr<TreeNode> right;
    int jurisdictionLeft;
    int jurisdictionRight;

    TreeNode(int endpoint)
        : endpoint(endpoint), left(nullptr), right(nullptr),
          jurisdictionLeft(endpoint), jurisdictionRight(endpoint) {}
};



class EndpointTree {
private:
    std::unique_ptr<TreeNode> root;
    std::unique_ptr<TreeNode> buildTree(const std::vector<int>& endpoints, int start, int end) {
        if (start > end) return nullptr; // Base case

        int mid = start + (end - start) / 2; // Middle index
        auto node = std::make_unique<TreeNode>(endpoints[mid]); // Create the node

        node->left = buildTree(endpoints, start, mid - 1);
        node->right = buildTree(endpoints, mid + 1, end);


        if (!node->left && !node->right) {
            node->jurisdictionLeft = node->endpoint;
            node->jurisdictionRight = (mid + 1 < endpoints.size()) ? endpoints[mid + 1] : INFTY; // +infinity for the rightmost leaf
        } else {
            node->jurisdictionLeft = node->left ? node->left->jurisdictionLeft : node->endpoint;
            node->jurisdictionRight = node->right ? node->right->jurisdictionRight : INFTY;
        }

        return node;
    }

public:
    EndpointTree(const std::vector<Query>& queries) {
        
        std::set<int> uniqueEndpoints;

        // Extract all unique endpoints from the queries
        for (const Query& query : queries) {
            uniqueEndpoints.insert(query.getLeft());
            uniqueEndpoints.insert(query.getRight());
        }

        std::vector<int> endpoints(uniqueEndpoints.begin(), uniqueEndpoints.end());  // set automatically sorts endpoints
        root = buildTree(endpoints, 0, endpoints.size() - 1);
    }

    
    TreeNode* getRoot() const { return root.get(); }
};


int main(){
    std::vector<Query> queries = {
        Query(1, 5, 10), 
        Query(3, 8, 15), 
        Query(2, 6, 5)
    };

    // Create an EndpointTree
    EndpointTree tree(queries);

    TreeNode* root = tree.getRoot();

    if (root) {
        std::cout << "Root's jurisdiction interval: [" 
                  << root->jurisdictionLeft << ", " 
                  << root->jurisdictionRight << ")\n";
    }
}
