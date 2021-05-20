#ifndef BINSTRTREE_H
#define BINSTRTREE_H
#include "TreeNode.cc"
/*类指针类型*/
class BinStrTree
{
private:
    TreeNode *root;
public:
    BinStrTree():root(new TreeNode()){};
    BinStrTree(TreeNode *&TN):root(TN){}
    /*拷贝构造函数*/
    BinStrTree(const BinStrTree& BST):root(BST.root){};
    /*赋值运算符*/
    BinStrTree& operator=(const BinStrTree&);
    ~BinStrTree();
};
#endif