#ifndef MYSP_H
#define MYSP_H
#include <functional>
template<typename T> class mySP
{
private:
    T* ptr;
    std::size_t *counts;
    std::function<void(T*)> del;
    void destroy(){
        if (!--*counts)
        {
            delete counts;
            del(ptr);
            counts=nullptr;
            ptr=nullptr;
        }
    }
public:
    //默认构造函数
    mySP():ptr(nullptr) , counts(nullptr) , del([](T* p){ delete p;}){}
    //拷贝构造函数
    mySP(mySP& sp):ptr(sp.ptr) , counts(sp.counts){}
    ~mySP();
};


#endif