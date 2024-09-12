#include <vector>
#include "../Query.h"
#include "../StreamElement.h"



class NaiveAlgorithm {

private:
    std::vector<Query>& query_list;

public:
    NaiveAlgorithm(std::vector<Query>& queries);
    void processElement(const StreamElement& element);
    void registerQuery(Query& query);
};
