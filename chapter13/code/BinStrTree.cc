#include "BinStrTree.h"

BinStrTree& BinStrTree::operator=(const BinStrTree& BST){
    root = BST.root;
}
BinStrTree::~BinStrTree(){
    delete root;
}