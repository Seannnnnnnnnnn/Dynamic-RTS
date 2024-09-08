#include <gtest/gtest.h>
#include "../EndpointTree.h"
#include "../Query.h"
#include "../StreamElement.h"

// tests element processing
TEST(EndpointTreeTest, StabsCorrectNumberOfNodes) {
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
    EndpointTree tree(queries);

    // elements within tree
    StreamElement element1(1, 1);
    ASSERT_EQ(5, tree.processElement(element1));
    
    StreamElement element2(9, 1);
    ASSERT_EQ(5, tree.processElement(element2));

    // elements that fall outside the tree
    StreamElement element3(0, 1);
    ASSERT_EQ(0, tree.processElement(element3));

    StreamElement element4(100, 1);
    ASSERT_EQ(0, tree.processElement(element4));

}


TEST(EndpointTreeTest, StabsCorrectNumberOfNodesSmallTree) {
    std::vector<Query> queries = {
        Query(1, 11, 10),
    };
    EndpointTree tree(queries);

    // elements within tree
    StreamElement element(1, 1);
    ASSERT_EQ(2, tree.processElement(element));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
