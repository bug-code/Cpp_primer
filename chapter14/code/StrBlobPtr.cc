#include "StrBlobPtr.h"
inline bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    bool flag=true;
    //检查对象是否存在
    auto lhsp = lhs.check(0 , "no vector") , rhsp=rhs.check(0,"no vector"); 
    if ( lhsp != rhsp )
    {
        auto lsize = lhsp->size() , rsize = rhsp->size();
        if (lsize==rsize)
        {
            auto beg1 = lhsp->cbegin() , beg2 = rhsp->cbegin();
            for (size_t i = 0; i < lhsp->size(); ++i)
            {
                if (*beg1++ != *beg2++)
                {
                    flag=false;
                }
            }
        }
        else
        {
            flag=false;
        }
    }
    return flag;
}

inline bool operator!=(const StrBlobPtr& lhs , const StrBlobPtr& rhs){
    return !operator==(lhs , rhs);
}   

inline bool operator<(const StrBlobPtr& lhs,const StrBlobPtr& rhs){
    auto lhsp=lhs.check(0 , "no vector"), rhsp=rhs.check(0,"no vector"); 
    for(auto beg1 = lhsp->cbegin() , beg2 = rhsp->cbegin() , en1 = lhsp->cend() , en2 = rhsp->cend(); beg1!=en1 && beg2!=en2 ; ++beg1 , ++beg2)
    {
        if (*beg1 != *beg2 )
        {
            return *beg1 < *beg2;
        }
    }    
    return lhs.size() < rhs.size();
}

inline StrBlobPtr StrBlobPtr::operator+(const size_t& i){
    auto tmp = *this;
    tmp+=i;
    return tmp;
}
inline StrBlobPtr StrBlobPtr::operator-(const size_t& i){
    auto tmp = *this;
    tmp+=i;
    return tmp;
}

inline StrBlobPtr& StrBlobPtr::operator+=(const size_t& i){
    curr-=i;
    check(curr ,"increment past begin of StrBlobPtr");
    return *this;
}
inline StrBlobPtr& StrBlobPtr::operator-=(const size_t& i){
    curr-=i;
    check(curr,"increment past end of StrBlobPtr");
    return *this;
}

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

/*练习14.30*/
inline string& StrBlobPtr::operator*()const{
    auto p= check(curr , "dereference out of range" );
    return (*p)[curr];
}
inline string* StrBlobPtr::operator->()const{
    return & this->operator*(); //返回的是指针，所以要地址
}

/*练习14.27*/
/*前置运算符*/
StrBlobPtr& StrBlobPtr::operator++(){
    check(curr , "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr& StrBlobPtr::operator--(){
    --curr;
    check(curr , "increment past begin of StrBlobPtr");
    return *this;
}
/*后置运算符*/
StrBlobPtr StrBlobPtr::operator++(int){
    auto tmp = *this;
    ++*this;//调用前置运算符
    return tmp;
}
StrBlobPtr StrBlobPtr::operator--(int){
    auto tmp = *this;
    --*this;
    return tmp;
}


// StrBlobPtr& StrBlobPtr::incr(){
//     check(curr , "increment past end of StrBlobPtr");
//     ++curr;
//     return *this;
// }
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
