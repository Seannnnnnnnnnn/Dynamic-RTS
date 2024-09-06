#include "TreeNode.h"

bool TreeNode::stabsJurisdictionInterval(int value){
    return jurisdictionLeft <= value <= jurisdictionRight;
}