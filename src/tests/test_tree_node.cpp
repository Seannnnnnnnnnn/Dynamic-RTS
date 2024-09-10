#include <gtest/gtest.h>
#include <limits>
#include "../TreeNode.h"


// Test case for the left endpoint of the jurisdiction interval
TEST(TreeNodeTest, StabsCorrectValueFiniteBounds) {
    TreeNode node;
    node.jurisdictionLeft = 9;
    node.jurisdictionRight = 13;
    
    ASSERT_TRUE(node.stabsJurisdictionInterval(10));
}


TEST(TreeNodeTest, DoesntStabIncorrectValueFiniteBounds) {
    TreeNode node;
    node.jurisdictionLeft = 1;
    node.jurisdictionRight = 9;
    ASSERT_FALSE(node.stabsJurisdictionInterval(10));
}


TEST(TreeNodeTest, StabsCorrectValueInfiniteBounds) {
    TreeNode node1;
    node1.jurisdictionLeft = 1;
    node1.jurisdictionRight = 9;
    ASSERT_FALSE(node1.stabsJurisdictionInterval(10));

    int infty = std::numeric_limits<int>::max();
    TreeNode node2;
    node2.jurisdictionLeft = 9;
    node2.jurisdictionRight = infty;
    ASSERT_TRUE(node2.stabsJurisdictionInterval(10));
    
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}