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
        Query(7, 14, 1),
        Query(10, 12, 1),
    };
    
    DTAlgorithm DT(queries);
    std::cout<<"created the DT Algorithm"<<std::endl;


    StreamElement streamElement(9, 100);
    std::cout<<"created a stream element"<<std::endl;

    DT.processElement(streamElement);
    std::cout<<"processed a stream element"<<std::endl;

    for (auto query : DT.getQuerySet()) {
        if (!query.alive) {
            std::cout<<"Matured query"<<std::endl;
        }
    }

    return 0;
}
