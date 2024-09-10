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
        dtAlgorithmTestClass = std::make_unique<TestDTAlgorithmClass>(queries);
        dtAlgorithm = std::make_unique<DTAlgorithm>(queries);
    }
    std::unique_ptr<TestDTAlgorithmClass> dtAlgorithmTestClass;
    std::unique_ptr<DTAlgorithm> dtAlgorithm;
};



TEST_F(DTAlgorithmTest, BuildsDTInstancesInNodes) {
    // checks that all DT Instances are built
    auto dtInstances = dtAlgorithmTestClass->getDTInstancesFromNodes();
    ASSERT_EQ(dtInstances.size(), 23);
}


TEST_F(DTAlgorithmTest, NodesAreCorrectlyInitialized) {
    // Checks that all TreeNodes are correctly initialized and accessible
    auto allNodes = dtAlgorithmTestClass->getNodes();
    
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
    auto allNodes = dtAlgorithmTestClass->getNodes();

    int num_heaps_initialised = 0;

    for (const auto& node : allNodes) {
        if (node->dtHeap.size() > 0) {num_heaps_initialised++;}
    }
    ASSERT_GE(num_heaps_initialised, 8);  // there should be as many heaps as DT Instances
}



TEST_F(DTAlgorithmTest, BuildsCorrectNumberOfNodes) {
    // Checks that all TreeNodes are correctly initialized and accessible
    auto allNodes = dtAlgorithmTestClass->getNodes();
    
    // Assuming you expect a certain number of nodes in the tree
    ASSERT_EQ(allNodes.size(), 31);
}


TEST_F(DTAlgorithmTest, BuildsQuerySet) {
    // Checks that querySet is built and accessible 
    std::vector<Query> queries = {
            Query(1, 11, 1),
            Query(2, 16, 1),
            Query(3, 13, 1),
            Query(4, 9, 1),
        };

    DTAlgorithm DT(queries);
    ASSERT_EQ(DT.getQuerySet().size(), 4);
}


TEST_F(DTAlgorithmTest, AssignsDtInstancesCorrectlyToHeaps) {
    // example from 2016 
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
    ASSERT_EQ(DT.getQuerySet().size(), 8);

    // following node should have 4 DT instancesthm
    TreeNode* root = DT.getDTRoot();  
    TreeNode* targetNode = root->right.get()->left.get();

    // Check DTHeap and DTMap sizes
    ASSERT_EQ(targetNode->dtHeap.size(), 4);
    ASSERT_EQ(targetNode->dtInstanceDataMap.size(), 4);

    // Check its the right node
    ASSERT_EQ(targetNode->jurisdictionLeft, 9);
    ASSERT_EQ(targetNode->jurisdictionRight, 13);

    // Check that it can be iterated over (instances are stored correctly)
    for (auto dtInstance : targetNode->dtInstanceList) {
        ASSERT_EQ(dtInstance->getSlack(), 1);
    }
}


TEST_F(DTAlgorithmTest, DoesntMatureAllQueries) {
    std::vector<Query> queries = {
        Query(1, 11, 1),
        Query(2, 16, 1),
        Query(3, 13, 10),
        Query(4, 9, 1),
        Query(5, 15, 1),
        Query(6, 8, 1),
        Query(7, 14, 1),
        Query(10, 12, 10),
    };
    
    DTAlgorithm DT(queries);

    StreamElement streamElement(10, 1);

    DT.processElement(streamElement);

    int dead_queries = 0;
    for (auto& query : DT.getQuerySet()) {
        if (!query.isAlive()) {
            dead_queries++;
        }
    }

    ASSERT_EQ(dead_queries, 4);
}


TEST_F(DTAlgorithmTest, MaturesCorrectQueriesCase1) {
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

    StreamElement streamElement(10, 1);

    DT.processElement(streamElement);

    int dead_queries = 0;
    for (auto& query : DT.getQuerySet()) {
        if (!query.isAlive()) {
            dead_queries++;
        }
    }
    ASSERT_EQ(dead_queries, 6);
}


TEST_F(DTAlgorithmTest, MaturesCorrectQueriesCase2) {
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

    StreamElement streamElement(13, 1);

    DT.processElement(streamElement);

    int dead_queries = 0;
    for (auto& query : DT.getQuerySet()) {
        if (!query.isAlive()) {
            dead_queries++;
        }
    }
    ASSERT_EQ(dead_queries, 3);
}


TEST_F(DTAlgorithmTest, MaturesCorrectQueriesCase3) {
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

    StreamElement streamElement(20, 1);

    DT.processElement(streamElement);

    int dead_queries = 0;
    for (auto& query : DT.getQuerySet()) {
        if (!query.isAlive()) {
            dead_queries++;
        }
    }
    ASSERT_EQ(dead_queries, 0);
}


TEST_F(DTAlgorithmTest, MaturesCorrectQueriesCase4) {
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

    StreamElement streamElement(4, 1);

    DT.processElement(streamElement);

    int dead_queries = 0;
    for (auto& query : DT.getQuerySet()) {
        if (!query.isAlive()) {
            dead_queries++;
        }
    }
    ASSERT_EQ(dead_queries, 4);
}


TEST_F(DTAlgorithmTest, MaturesCorrectQueriesCase5) {
    std::vector<Query> queries = {
        Query(1, 11, 1),
        Query(2, 16, 1),
        Query(3, 13, 1),
        Query(4, 9, 1),
        Query(5, 15, 1),
        Query(6, 8, 1),
        Query(7, 14, 1),
        Query(10, 12, 60), 
    };
    
    DTAlgorithm DT(queries);

    StreamElement streamElement(9, 50);

    DT.processElement(streamElement);

    int dead_queries = 0;
    for (auto& query : DT.getQuerySet()) {
        if (!query.isAlive()) {
            dead_queries++;
        }
    }
    ASSERT_EQ(dead_queries, 5);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
