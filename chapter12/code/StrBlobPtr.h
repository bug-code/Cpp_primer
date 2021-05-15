#ifndef STRBLOBPTR
#define STRBLOBPTR

#include "StrBlob.h"
using namespace std;
class StrBlobPtr
{
private:
    shared_ptr<vector<string>> check(size_t,const string &)const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
public:

    StrBlobPtr():curr(0){};
    StrBlobPtr(StrBlob &a , size_t sz=0):wptr(a.data),curr(sz){}
    //解引用
    string& deref()const;
    bool empty() const {return (wptr.lock())->empty();}
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
    StrBlobPtr& incr();
    ~StrBlobPtr()=default;
};
#endif