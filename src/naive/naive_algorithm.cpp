#include "naive_algorithm.h"

NaiveAlgorithm::NaiveAlgorithm(std::vector<Query>& queries) : query_list(queries) {}


void NaiveAlgorithm::registerQuery(Query& query) {
    query_list.push_back(query);
}


void NaiveAlgorithm::processElement(const StreamElement& element) {
    for (auto query : query_list) {
        query.tau -= element.weight;
        if (query.tau <= 0) {
            query.alive = false;
        }
    }
}
