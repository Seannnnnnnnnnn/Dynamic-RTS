#include <iostream>
#include "Query.h"
#include "EndpointTree.h"
#include "StreamElement.h"
#include "DTAlgorithm.h"


int main() {
    // Define some example queries
    std::vector<Query> queries = {
        Query(1, 11, 1),
        Query(2, 16, 1),
        Query(3, 13, 1),
        Query(4, 9, 1),
        Query(5, 15, 1),
        Query(6, 8, 1),
        Query(7, 14, 100),
        Query(10, 12, 1),
    };
    
    DTAlgorithm DT(queries);

    DT.processElement(StreamElement(13, 1));
    DT.processElement(StreamElement(4, 1));
    DT.processElement(StreamElement(8, 25));
    DT.processElement(StreamElement(9, 10));
    DT.processElement(StreamElement(9, 26));

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
