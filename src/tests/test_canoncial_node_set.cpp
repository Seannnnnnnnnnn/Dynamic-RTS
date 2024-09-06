#include <gtest/gtest.h>
#include "../EndpointTree.h"
#include "../Query.h"

// Test case for the left endpoint of the jurisdiction interval
// Test case taken from 2016 paper
TEST(EndpointTreeTest, HasCorrectCanonicalNodeSet) {
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

    Query test_query(5, 15, 10);
    std::vector<TreeNode*> canonicalNodes = tree.findCanonicalNodeSet(test_query);

    // check we have the right amount of nodes:
    ASSERT_EQ(3, canonicalNodes.size());
    
    // check that we have the right nodes:
    TreeNode* node0 = canonicalNodes[0];
    ASSERT_EQ(5, node0->jurisdictionLeft);
    ASSERT_EQ(9, node0->jurisdictionRight);

    TreeNode* node1 = canonicalNodes[1];
    ASSERT_EQ(9, node1->jurisdictionLeft);
    ASSERT_EQ(13, node1->jurisdictionRight);

    TreeNode* node2 = canonicalNodes[2];
    ASSERT_EQ(13, node2->jurisdictionLeft);
    ASSERT_EQ(15, node2->jurisdictionRight);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
