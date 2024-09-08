#include <gtest/gtest.h>
#include "../DistributedTracking.h"
#include "../TreeNode.h"
#include "../Query.h"


TEST(DistributedTrackingTest, BuildsCorrectly) {
    Query coordinator(1, 5, 9);
    
    std::vector<TreeNode*> participants;
    

    for (int i = 0; i < 5; ++i) {
        auto node = new TreeNode();
        participants.push_back(node);
    }    
    DistributedTracking dtInstance(coordinator, participants);
    
    ASSERT_EQ(dtInstance.getParticipants().size(), 5);
    ASSERT_EQ(dtInstance.getThreshold(), 9);

    for (auto node : participants) {
        delete node;
    }
}


TEST(DistributedTrackingTest, CreatesCorrectSlackWhenSmall) {
    Query coordinator(1, 5, 9);
    
    std::vector<TreeNode*> participants;
    
    
    for (int i = 0; i < 3; ++i) {
        auto node = new TreeNode();
        participants.push_back(node);
    }    
    DistributedTracking dtInstance(coordinator, participants);
    
    int h = dtInstance.getParticipants().size();
    int threshold = coordinator.getThreshold();

    ASSERT_EQ(h, 3);
    ASSERT_EQ(threshold, 9);
    ASSERT_LT(threshold, 6 * h);
    ASSERT_EQ(dtInstance.getSlack(), 1);

    for (auto node : participants) {
        delete node;
    }
}


TEST(DistributedTrackingTest, CreatesCorrectSlackWhenBig) {
    Query coordinator(1, 5, 100);
    
    std::vector<TreeNode*> participants;
    
    
    for (int i = 0; i < 3; ++i) {
        auto node = new TreeNode();
        participants.push_back(node);
    }    
    DistributedTracking dtInstance(coordinator, participants);
    
    int h = dtInstance.getParticipants().size();
    int threshold = coordinator.getThreshold();

    ASSERT_EQ(h, 3);
    ASSERT_EQ(threshold, 100);
    ASSERT_GT(threshold, 6 * h);
    ASSERT_EQ(dtInstance.getSlack(), 16);

    for (auto node : participants) {
        delete node;
    }
}



// Entry point for running all the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
