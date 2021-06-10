#ifndef STRBLOBPTR
#define STRBLOBPTR

#include "StrBlob.h"
using namespace std;
class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr& , const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr& , const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr& ,const StrBlobPtr&);

private:
    shared_ptr<vector<string>> check(size_t,const string &)const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
public:

    StrBlobPtr():curr(0){};
    StrBlobPtr(StrBlob &a , size_t sz=0):wptr(a.data),curr(sz){}
    //解引用
    string& deref()const;
    string& operator*()const;
    string* operator->()const;
    /*练习14.26 下标运算符*/
    string& operator[](const size_t& n){ return *(wptr.lock()->begin()+n);}
    /*练习14.27*/
    /*前置运算符*/
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    /*后置运算符*/
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    /*练习14.28*/
    StrBlobPtr operator+(const size_t&);
    StrBlobPtr operator-(const size_t&);
    StrBlobPtr& operator+=(const size_t&);
    StrBlobPtr& operator-=(const size_t&);
    const string& operator[](const size_t& n)const {return *(wptr.lock()->cbegin()+n);}
    bool empty() const {return (wptr.lock())->empty();}
    size_t size()const{return wptr.lock()->size();}
    void push_back(const string &s){wptr.lock()->push_back(s);}
    void pop_back();
    string& front();
    string& back();
    const string& front()const;
    const string& back()const;
    vector<string>::iterator begin();
    vector<string>::iterator end();
    vector<string>::const_iterator cbegin();
    vector<string>::const_iterator cend();
    size_t& getcurr(){return curr;}
    //前缀递增
    // StrBlobPtr& incr();
    ~StrBlobPtr()=default;
};
#endif