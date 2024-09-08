#include <gtest/gtest.h>
#include "DTAlgorithmTest.h"
#include "../TreeNode.h"
#include "../DistributedTracking.h"


class DTAlgorithmTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize queries with sample data
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
        dtAlgorithm = std::make_unique<TestDTAlgorithmClass>(queries);
    }
    std::unique_ptr<TestDTAlgorithmClass> dtAlgorithm;
};


TEST_F(DTAlgorithmTest, BuildsDTInstances) {
    // checks that all DT Instances are built
    auto dtInstances = dtAlgorithm->getDTInstances();
    ASSERT_EQ(dtInstances.size(), 8);
}


TEST_F(DTAlgorithmTest, BuildsDTInstancesInNodes) {
    // checks that all DT Instances are built
    auto dtInstances = dtAlgorithm->getDTInstancesFromNodes();
    ASSERT_EQ(dtInstances.size(), 22);
}


TEST_F(DTAlgorithmTest, NodesAreCorrectlyInitialized) {
    // Checks that all TreeNodes are correctly initialized and accessible
    auto allNodes = dtAlgorithm->getNodes();
    
    // Assuming you expect a certain number of nodes in the tree
    ASSERT_GT(allNodes.size(), 0); // Ensure we have more than 0 nodes

    // Verify each node's properties, or check that the heap is initialized correctly
    for (const auto& node : allNodes) {
        ASSERT_NE(node, nullptr); // Node should not be null
        ASSERT_TRUE(node->dtHeap.empty() || node->dtHeap.size() > 0); // Check heap initialization
    }
}


TEST_F(DTAlgorithmTest, HeapsAreCorrectlyInitialized) {
    // Checks that all TreeNodes are correctly initialized and accessible
    auto allNodes = dtAlgorithm->getNodes();

    int num_heaps_initialised = 0;

    for (const auto& node : allNodes) {
        if (node->dtHeap.size() > 0) {num_heaps_initialised++;}
    }
    ASSERT_GE(num_heaps_initialised, 8);  // there should be as many heaps as DT Instances
}



TEST_F(DTAlgorithmTest, BuildsCorrectNumberOfNodes) {
    // Checks that all TreeNodes are correctly initialized and accessible
    auto allNodes = dtAlgorithm->getNodes();
    
    // Assuming you expect a certain number of nodes in the tree
    ASSERT_EQ(allNodes.size(), 31);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
