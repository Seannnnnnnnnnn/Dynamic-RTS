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
    Query coordinator(0, 10, 16);  // Threshold of 16

    // Store unique_ptrs to keep them alive
    std::vector<std::unique_ptr<TreeNode>> participants;
    for (int i = 0; i < 3; ++i) {
        participants.push_back(std::make_unique<TreeNode>());
    }

    // Extract raw pointers for use with DistributedTracking
    std::vector<TreeNode*> participantPtrs;
    for (const auto& participant : participants) {
        participantPtrs.push_back(participant.get());
    }

    auto dtInstance = std::make_unique<DistributedTracking>(coordinator, participantPtrs);
    DistributedTracking* dtInstancePtr = dtInstance.get();

    for (auto participant : participantPtrs) {
        participant->dtInstanceDataMap[dtInstancePtr] = {0, dtInstancePtr->getSlack()};
        participant->initialiseHeap();
    }

    // Check that participants have non-empty maps and heaps
    for (auto participant : participantPtrs) {
        ASSERT_FALSE(participant->dtHeap.empty());
        ASSERT_FALSE(participant->dtInstanceDataMap.empty());
    }
    ASSERT_EQ(dtInstance->getSlack(), 1);  // Check that we branch correctly in processSignal

    // Small value to not mature the DT instance
    dtInstance->processSignal(1);

    // Check that participants have non-empty maps and heaps
    for (auto participant : participantPtrs) {
        ASSERT_FALSE(participant->dtHeap.empty());
        ASSERT_FALSE(participant->dtInstanceDataMap.empty());
        ASSERT_TRUE(dtInstance->isAlive());
        ASSERT_TRUE(coordinator.alive);
    }
}


TEST(DistributedTrackingTest, HandlesMaturityWhenSmall){

    // set up
    Query coordinator(0, 10, 1);  // threshold of 1
    
    // Store unique_ptrs to keep them alive
    std::vector<std::unique_ptr<TreeNode>> participants;
    for (int i = 0; i < 3; ++i) {
        participants.push_back(std::make_unique<TreeNode>());
    }

    // Extract raw pointers for use with DistributedTracking
    std::vector<TreeNode*> participantPtrs;
    for (const auto& participant : participants) {
        participantPtrs.push_back(participant.get());
    }       
    
    auto dtInstance = std::make_unique<DistributedTracking>(coordinator, participantPtrs);
    DistributedTracking* dtInstancePtr = dtInstance.get();

    for (auto participant : participantPtrs) {
        participant->dtInstanceDataMap[dtInstancePtr] = {0, dtInstancePtr->getSlack()};
        participant->initialiseHeap();
    }

    // check that participants have non-empty maps and Heaps
    for (auto participant : participantPtrs) {
        ASSERT_FALSE(participant->dtHeap.empty());
        ASSERT_FALSE(participant->dtInstanceDataMap.empty());
    }
    ASSERT_EQ(dtInstance->getSlack(), 1);  // check that we branch correctly in processSignal

    // large increase to mature the DT Instances
    dtInstance->processSignal(100);

    // check that particpants have empty maps
    for (auto participant : participantPtrs) {
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
