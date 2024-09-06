#include "TreeNode.h"

bool TreeNode::stabsJurisdictionInterval(int value){
    return jurisdictionLeft <= value <= jurisdictionRight;
}

void TreeNode::incrementCounter(int weight){
    counter += weight;
}