#include <iostream>
#include "Query.h"
#include "EndpointTree.h"
#include "StreamElement.h"

int main() {
    // Define some example queries
    std::vector<Query> queries = {
        Query(1, 11, 10),
        Query(2, 16, 10),
        Query(3, 13, 10),
        Query(4, 9, 10),
        Query(5, 15, 10),
        Query(6, 8, 10),
        Query(7, 14, 10),
        Query(10, 12, 10),
    };
    
    // Create an EndpointTree from the queries
    EndpointTree tree(queries);
    
    // Define a query to test
    Query testQuery(5, 15, 10);
    
    // Get the canonical node set for the test query
    std::vector<TreeNode*> canonicalNodes = tree.findCanonicalNodeSet(testQuery);
    
    // Output the results
    std::cout << "Canonical nodes for query [5, 15):\n";
    for (auto node : canonicalNodes) {
        std::cout << "Node with endpoint: " << node->endpoint 
                  << ", jurisdictionLeft: " << node->jurisdictionLeft 
                  << ", jurisdictionRight: " << node->jurisdictionRight << "\n";
    }

    // build a stream element and pass it through the tree: 
    StreamElement element(2, 10);
    tree.processElement(element);
    std::cout<<"processed a stream element";
    return 0;
}
