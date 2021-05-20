#ifndef TREENODE_H
#define TREENODE_H
#include <string>
using std::string;
class TreeNode
{
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(const string &s = string()):value(s) , count(0),left(new TreeNode()),right(new TreeNode()){};
    /*拷贝构造函数*/
    TreeNode(const TreeNode& TN):value(TN.value),count(TN.count),left(TN.left),right(TN.right){}
    /*赋值运算符*/
    TreeNode& operator=(const TreeNode&);
    ~TreeNode();
};

#endif