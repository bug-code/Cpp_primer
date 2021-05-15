#include "StrBlobPtr.h"
shared_ptr<vector<string>> StrBlobPtr::check(size_t i,const string &msg)const{
    auto ret=wptr.lock();
    if (!ret)
    {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size())
    {
        throw out_of_range(msg);
    }
    return ret;
}

void StrBlobPtr::pop_back(){
    auto sp=check(0,"vector is empty");
    sp->pop_back();
}
string& StrBlobPtr::front(){
    auto sp=check(0,"vector is empty");
    return sp->front();
}
string& StrBlobPtr::back(){
    auto sp=check(0,"vector is empty");
    return sp->back();
}
const string& StrBlobPtr::front()const{
    auto sp=check(0,"vector is empty");
    return sp->front();
}

const string& StrBlobPtr::back()const{
    auto sp=check(0,"vector is empty");
    return sp->back();
}

string& StrBlobPtr::deref()const{
    auto p = check(curr , "dereference out of range");
    return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr(){
    check(curr , "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
vector<string>::iterator StrBlobPtr::begin(){
    return wptr.lock()->begin();
}

vector<string>::iterator StrBlobPtr::end(){
    return wptr.lock()->end();
}
vector<string>::const_iterator StrBlobPtr::cbegin(){
    return wptr.lock()->cbegin();
}
vector<string>::const_iterator StrBlobPtr::cend(){
    return wptr.lock()->cend();
}
