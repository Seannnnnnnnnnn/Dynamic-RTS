#include <iostream>
#include "Query.h"
#include "EndpointTree.h"

int main() {
    // Define some example queries
    std::vector<Query> queries = {
        Query(1, 5, 10),
        Query(3, 8, 15),
        Query(6, 10, 12)
    };
    
    // Create an EndpointTree from the queries
    EndpointTree tree(queries);
    
    // Define a query to test
    Query testQuery(3, 8, 15);
    
    // Get the canonical node set for the test query
    std::vector<TreeNode*> canonicalNodes = tree.findCanonicalNodeSet(testQuery);
    
    // Output the results
    std::cout << "Canonical nodes for query [3, 8):\n";
    for (auto node : canonicalNodes) {
        std::cout << "Node with endpoint: " << node->endpoint 
                  << ", jurisdictionLeft: " << node->jurisdictionLeft 
                  << ", jurisdictionRight: " << node->jurisdictionRight << "\n";
    }

    return 0;
}
