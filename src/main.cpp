#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory>


using QueryList = std::vector<Query>;

struct Query{
    int l;  // left endpoint
    int r;  // right endpoint
    int tau;  
    int count = 0; 
    bool alive = true;  

    Query(int l, int r, int tau) : l(l), r(r), tau(tau), alive(true) {}
    inline bool isValid() const {return l < r;}
    inline int getLeft() {return l;}
    inline int getRight() {return r;}
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
    TreeNode(int endpoint) : endpoint(endpoint), left(nullptr), right(nullptr) {}
};



class EndpointTree {
private:

    QueryList query_set; 
    std::unique_ptr<TreeNode> root;
    std::unique_ptr<TreeNode> buildTree(const std::vector<int>& endpoints, int start, int end) {
        if (start > end) return nullptr; // Base case

        int mid = start + (end - start) / 2; // Middle index
        auto node = std::make_unique<TreeNode>(endpoints[mid]); // Create the node

        // Recursively build left and right subtrees
        node->left = buildTree(endpoints, start, mid - 1);
        node->right = buildTree(endpoints, mid + 1, end);

        return node;
    }

public:
    EndpointTree(const std::vector<Query>& queries) {
        
        query_set = queries;
        std::set<int> uniqueEndpoints;

        // Extract all unique endpoints from the queries
        for (const Query& query : queries) {
            uniqueEndpoints.insert(query.getLeft());
            uniqueEndpoints.insert(query.getRight());
        }

        // Convert set to sorted vector
        std::vector<int> endpoints(uniqueEndpoints.begin(), uniqueEndpoints.end());

        // Build the height-balanced binary tree
        root = buildTree(endpoints, 0, endpoints.size() - 1);
    }

    // Function to access the root node (for testing or further operations)
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

    // Access the root and perform further operations
    TreeNode* root = tree.getRoot();
    std::cout<<"hello world\n";
}
