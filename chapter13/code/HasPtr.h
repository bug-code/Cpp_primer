#ifndef HASPTR_H
#define HASPTR_H
#include <string>
#include <new>
using std::string;
class HasPtr
{
    friend void swap(HasPtr& , HasPtr&);
private:
    string *ps;
    int i;
    size_t *use;
public:
    HasPtr(const string &s=string() , const int& val=0):ps(new string(s)),i(val),use(new size_t(1)){}
    /*练习13.5*/
    /*简单拷贝指针，类指针指向同一块内存，类指针行为*/
    HasPtr(const HasPtr &hp):ps(hp.ps),i(hp.i),use(hp.use){++*use;}//拷贝构造函数
    /*创建新动态对象，类值行为*/
    // HasPtr(const HasPtr &hp):ps(new string(*hp.ps)),i(hp.i){}//拷贝构造函数
    //移动构造函数
    HasPtr(HasPtr&&)noexcept;
    HasPtr& operator=(HasPtr HP);
    //移动赋值运算符
    HasPtr& operator=(HasPtr&&)noexcept;
    HasPtr& swap(HasPtr&);
    string getStr()const{return *ps;}
    int getInt()const{return i;}
    bool operator<(const HasPtr&);
    ~HasPtr();
};

#endif