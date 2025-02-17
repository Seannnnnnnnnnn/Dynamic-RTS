#pragma once

#include <vector>
#include <algorithm>
#include "Query.h"
#include "StreamElement.h"

struct TreeNode;  // forward decleration to avoid circular dependancy

class DistributedTracking {
public:
    DistributedTracking(Query& coordinator, std::vector<TreeNode*>& participants);
    void processSignal(int counterChange);  // called when receiving signal
    bool isAlive() const;  // flag for if the DistributedTracking instance is still alive
    int getSlack() const;
    int getThreshold() const;
    std::vector<TreeNode*> getParticipants();

private:
    Query& coordinator;
    std::vector<TreeNode*> participants;
    int slack;
    int threshold;
    int numSignalsReceived;
    int calculateAndSetSlack();
    void processMaturity();
};
