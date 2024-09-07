#include <iostream>
#include "Query.h"
#include "EndpointTree.h"
#include "StreamElement.h"
#include "DTAlgorithm.h"

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
    
    DTAlgorithm DT(queries);
    
    StreamElement streamElement(2, 100);
    
    std::cout<<"processed a stream element"<<std::endl;

    for (auto query : DT.getQuerySet()) {
        if (not query.alive) {
            std::cout<<"Matured query"<<std::endl;
        }
    }

    return 0;
}
