#include <iostream>
#include <vector>
#include "EndpointTree.h"
#include "Query.h"

int main() {
    // Create some queries
    std::vector<Query> queries = {
        Query(1, 5, 10),
        Query(2, 6, 15),
        Query(4, 8, 20),
        Query(7, 9, 5)
    };

    // Instantiate the EndpointTree with the list of queries
    EndpointTree tree(queries);

    // Access the root node to check if the tree is built correctly
    TreeNode* root = tree.getRoot().get();
    
    // Output the root endpoint and its jurisdiction interval
    std::cout << "Root Endpoint: " << root->endpoint << std::endl;
    std::cout << "Jurisdiction Interval: [" << root->jurisdictionLeft 
                << ", " << root->jurisdictionRight << "]" << std::endl;


    return 0;
}
