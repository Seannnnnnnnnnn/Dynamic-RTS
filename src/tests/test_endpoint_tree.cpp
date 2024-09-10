#include <gtest/gtest.h>
#include "../EndpointTree.h"
#include "../Query.h"

// Test case for the left endpoint of the jurisdiction interval
TEST(EndpointTreeTest, LeftEndpointIsMinimum) {
    std::vector<Query> queries = {
        Query(1, 5, 10),
        Query(2, 6, 15),
        Query(4, 8, 20),
        Query(7, 9, 5)
    };

    EndpointTree tree(queries);
    TreeNode* root = tree.getRoot().get();
    
    ASSERT_NE(root, nullptr); // Ensure root is not null
    EXPECT_EQ(root->jurisdictionLeft, 1); // The minimum endpoint is 1
}


TEST(EndpointTreeTest, SetCorrectMaximumMinimum) {
    std::vector<Query> queries = {
        Query(1, 5, 10),
        Query(2, 6, 15),
        Query(4, 8, 20),
        Query(7, 9, 5),
        Query(-1, 100, 10),
    };

    EndpointTree tree(queries);

    ASSERT_EQ(tree.maximum_endpoint, 100);
    ASSERT_EQ(tree.minimum_endpoint, -1);
}
 
 
// Test case for the right endpoint of the jurisdiction interval
TEST(EndpointTreeTest, RightEndpointIsInfinity) {
    std::vector<Query> queries = {
        Query(1, 5, 10),
        Query(2, 6, 15),
        Query(4, 8, 20),
        Query(7, 9, 5)
    };

    EndpointTree tree(queries);
    TreeNode* root = tree.getRoot().get();
    
    ASSERT_NE(root, nullptr); // Ensure root is not null
    EXPECT_EQ(root->jurisdictionRight, INFTY); // The rightmost jurisdiction should be infinity
}

// Test case for leaves having correct jurisdiction intervals
TEST(EndpointTreeTest, LeavesHaveCorrectJurisdictionIntervals) {
    std::vector<Query> queries = {
        Query(1, 5, 10),
        Query(3, 7, 20),
        Query(8, 12, 15)
    };

    EndpointTree tree(queries);
    TreeNode* root = tree.getRoot().get();
    
    ASSERT_NE(root, nullptr); // Ensure root is not null

    // Find the leftmost and rightmost leaves
    TreeNode* leftLeaf = root->left.get();
    while (leftLeaf && leftLeaf->left) leftLeaf = leftLeaf->left.get();

    TreeNode* rightLeaf = root->right.get();
    while (rightLeaf && rightLeaf->right) rightLeaf = rightLeaf->right.get();

    ASSERT_NE(leftLeaf, nullptr);
    ASSERT_NE(rightLeaf, nullptr);

    // Check jurisdiction intervals for the leaves
    EXPECT_EQ(leftLeaf->jurisdictionLeft, 1);
    EXPECT_EQ(leftLeaf->jurisdictionRight, 3);
    EXPECT_EQ(rightLeaf->jurisdictionLeft, 12);
    EXPECT_EQ(rightLeaf->jurisdictionRight, INFTY);
}


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
