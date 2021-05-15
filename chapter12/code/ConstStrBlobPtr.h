#ifndef CONSTSTRBLOBPTR
#define CONSTSTRBLOBPTR
#include "StrBlob.h"
using namespace std;
class ConstStrBlobPtr
{
private:
    shared_ptr<vector<string>> check(size_t,const string &)const;
    const weak_ptr<vector<string>> wptr;
    size_t curr;
public:
    //StrBlob是vector<string>类型的shared_ptr
    // StrBlobPtr():curr(0){};
    ConstStrBlobPtr(const StrBlob &a , size_t sz=0):wptr(a.data),curr(sz){}
    //解引用
    string& deref()const;
    size_t& getcurr(){return curr;}
    //前缀递增
    StrBlobPtr& incr();
    ~ConstStrBlobPtr()=default;
};
#endif