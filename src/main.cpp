#include <iostream>
#include "Query.h"
#include "EndpointTree.h"
#include "StreamElement.h"
#include "DTAlgorithm.h"

// TODO: final debugging - make sure we kill 6 of the below queries (currently kill 5)

int main() {
    // Define some example queries
    std::vector<Query> queries = {
        Query(1, 11, 1),
        Query(2, 16, 1),
        Query(3, 13, 1),
        Query(4, 9, 1),
        Query(5, 15, 1),
        Query(6, 8, 1),
        Query(7, 14, 1),
        Query(10, 12, 1),  // you're alive for some reason
    };
    
    DTAlgorithm DT(queries);

    StreamElement streamElement(10, 1);

    DT.processElement(streamElement);

    int dead_queries = 0;
    for (auto& query : DT.getQuerySet()) {
        if (!query.isAlive()) {
            std::cout<<"killed query on : [" << query.getLeft() <<"," << query.getRight()<<")\n";
            dead_queries++;
        }
    }
    std::cout<<"Matured " << dead_queries << " RTS Queries" << std::endl;

    return 0;
}
