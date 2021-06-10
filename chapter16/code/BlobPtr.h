#ifndef BLOBPTR_H
#define BLOBPTR_H
#include "Blob.h"
#include <stdexcept>
template<typename T> bool operator==(const BlobPtr<T>& , const BlobPtr<T>&);
template<typename T> bool operator!=(const BlobPtr<T>& , const BlobPtr<T>&);
template<typename T> bool operator<(const BlobPtr<T>& , const BlobPtr<T>&);

template<typename T> class BlobPtr
{
    friend bool operator==(const BlobPtr<T>& , const BlobPtr<T>&);
    friend bool operator!=(const BlobPtr<T>& , const BlobPtr<T>&);
    friend bool operator<(const BlobPtr<T>& , const BlobPtr<T>&);
private:
    std::shared_ptr<std::vector<T>> check(const size_t& , const std::string&)const;
    std::weak_ptr<std::vector<T>> wptr;
    size_t curr;
public:
    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;
    BlobPtr():wptr(std::weak_ptr<std::vector<T>>()) , curr(0) {}
    BlobPtr(Blob<T>& b , size_t& sz=0):wptr(b.data) , curr(sz){}
    /*解引用*/
    T& operator*()const;
    T* operator->()const;
    /*下标运算符*/
    T& operator[](const size_t& n){return *(wptr.lock()->begin()+n);}
    /*前置运算符*/
    BlobPtr operator++();
    BlobPtr operator--();
    /*后置运算符*/
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    /*指针加减*/
    BlobPtr operator+=(const size_t&);
    BlobPtr operator-=(const size_t&);
    BlobPtr operator+(const size_t&);
    BlobPtr operator-(const size_t&);

    /*常量的下标运算*/
    const T& operator[](const size_t& n)const{return *(wptr.lock()->cbegin()+n);}
    /*为空*/
    bool empty(){return wptr.lock()->empty();}
    size_t size()const {return wptr.lock()->size();}
    /*增删*/
    void push_back(const T& t){wptr.lock()->push_back(t);}
    void pop_back();
    /*查*/
    T& front();
    T& back();
    const T& front()const;
    const T& back()const;
    iterator begin();
    iterator end();
    const_iterator cbegin()const;
    const_iterator cend()const;
    ~BlobPtr()=default;
};
template<typename T> std::shared_ptr<std::vector<T>> BlobPtr<T>::check(const size_t& i , const std::string& msg) const{
    auto ret=wptr.lock();
    if(!ret) throw std::runtime_error("unbound BlobPtr");
    if ()
    {
        throw std::out_of_range(msg);
    }
    return ret;
}
template<typename T> T& BlobPtr<T>::operator*()const{
    auto p=check(curr , "dereference out of range");
    return (*p)[curr];
}
template<typename T> T* BlobPtr<T>::operator->()const{
    return &this->operator*();//返回地址
}
/*前置运算符*/
template<typename T>  BlobPtr<T>  BlobPtr<T>::operator++(){
    check(curr , "increment past end of BlobPtr");
    ++curr;
    return *this;
}
template<typename T> BlobPtr<T> BlobPtr<T>::operator--(){
    --curr;
    check(curr,"decrement past begin of BlobPtr");
    return *this;
}
template<typename T> BlobPtr<T> BlobPtr<T>::operator++(int){
    auto tmp = *this;
    ++*this; //调用前置运算符
    return tmp;
}
template<typename T> BlobPtr<T> BlobPtr<T>::operator--(int){
    auto tmp = *this;
    --*this;
    return tmp;
}
/*指针加减*/
template<typename T> BlobPtr<T> BlobPtr<T>::operator+=(const size_t& i){
    curr+=i;
    check(curr , "increment past begin of BlobPtr");
    return *this;
}
template<typename T> BlobPtr<T> BlobPtr<T>::operator-=(const size_t& i){
    curr-=i;
    check(curr , "increment past end of BlobPtr");
    return *this;
}
template<typename T> BlobPtr<T> BlobPtr<T>::operator+(const size_t& i){
    auto tmp = *this;
    tmp+=i;
    return tmp;
}
template<typename T> BlobPtr<T> BlobPtr<T>::operator-(const size_t& i){
    auto tmp = *this;
    tmp-=i;
    return tmp;
}
/*增删*/
template<typename T> void BlobPtr<T>::pop_back(){
    auto sp = check(0,"vessle is empty");
    sp->pop_back();
}
/*查*/
template<typename T> T& BlobPtr<T>::front(){
    auto sp = check(0,"vessle is empty!");
    return sp->front();
}
template<typename T> T& BlobPtr<T>::back(){
    auto sp = check(0 , "vessle is empty");
    return sp->back();
}
template<typename T> const T& BlobPtr<T>::front()const{
    auto sp=check(0,"vessle is empty");
    return sp->front();
}
template<typename T> const T& BlobPtr<T>::back()const{
    auto sp=check(0,"vessle is empty");
    return sp->back();
}
template<typename T> BlobPtr<T>::iterator BlobPtr<T>::begin(){
    return wptr.lock()->begin();
}
template<typename T> BlobPtr<T>::iterator BlobPtr<T>::end(){
    return wptr.lock()->end();
}
template<typename T> BlobPtr<T>::const_iterator BlobPtr<T>::cbegin()const{
    return wptr.lock()->cbegin();
}
template<typename T> BlobPtr<T>::const_iterator  BlobPtr<T>::cend()const{
    return wptr.lock()->cend();
}
#endif