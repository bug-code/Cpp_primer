#include "TreeNode.h"
TreeNode& TreeNode::operator=(const TreeNode &TN){
    value=TN.value;
    count=TN.count;
    left=TN.left;
    right=TN.right;
    return *this;
}
TreeNode::~TreeNode(){
    delete left;
    delete right;
}