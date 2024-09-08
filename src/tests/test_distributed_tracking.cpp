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


TEST(DistributedTrackingTest, ProcessSignalWithoutMaturity){
    // Tests that we can process a signal when the counter change is small enough to not mature

    // set up
    Query coordinator(0, 10, 16);  // threshold of 100
    
    std::vector<TreeNode*> participants;
    for (int i = 0; i < 3; ++i) {
        participants.push_back(std::make_unique<TreeNode>().get());
    }        
    
    auto dtInstance = std::make_unique<DistributedTracking>(coordinator, participants);
    DistributedTracking* dtInstancePtr = dtInstance.get();

    for (auto participant : participants) {
        participant->dtInstanceDataMap[dtInstancePtr] = {0, dtInstancePtr->getSlack()};
        participant->initialiseHeap();
    }

    // check that participants have non-empty maps and Heaps
    for (auto participant : participants) {
        ASSERT_FALSE(participant->dtHeap.empty());
        ASSERT_FALSE(participant->dtInstanceDataMap.empty());
    }
    ASSERT_EQ(dtInstance->getSlack(), 1);  // check that we branch correctly in processSignal

    // small value to not mature the DT instance
    dtInstance->processSignal(1);

    // check that particpants have empty maps
    for (auto participant : participants) {
        ASSERT_FALSE(participant->dtHeap.empty());
        ASSERT_FALSE(participant->dtInstanceDataMap.empty());
        ASSERT_TRUE(dtInstance->isAlive());
        ASSERT_TRUE(coordinator.alive);
    }
}



TEST(DistributedTrackingTest, HandlesMaturityWhenSmall){

    // set up
    Query coordinator(0, 10, 1);  // threshold of 1
    
    std::vector<TreeNode*> participants;
    for (int i = 0; i < 3; ++i) {
        participants.push_back(std::make_unique<TreeNode>().get());
    }        
    
    auto dtInstance = std::make_unique<DistributedTracking>(coordinator, participants);
    DistributedTracking* dtInstancePtr = dtInstance.get();

    for (auto participant : participants) {
        participant->dtInstanceDataMap[dtInstancePtr] = {0, dtInstancePtr->getSlack()};
        participant->initialiseHeap();
    }

    // check that participants have non-empty maps and Heaps
    for (auto participant : participants) {
        ASSERT_FALSE(participant->dtHeap.empty());
        ASSERT_FALSE(participant->dtInstanceDataMap.empty());
    }
    ASSERT_EQ(dtInstance->getSlack(), 1);  // check that we branch correctly in processSignal

    // large increase to mature the DT Instances
    dtInstance->processSignal(100);

    // check that particpants have empty maps
    for (auto participant : participants) {
        ASSERT_TRUE(participant->dtHeap.empty());
        ASSERT_TRUE(participant->dtInstanceDataMap.empty());
        ASSERT_FALSE(dtInstance->isAlive());
        ASSERT_FALSE(coordinator.alive);
    }
}


// Entry point for running all the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
