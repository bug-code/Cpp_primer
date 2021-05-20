#ifndef FOO_H
#define FOO_H
#include "HasPtr.cc"
class Foo
{
   friend void swap(Foo&  , Foo&);
private:
    HasPtr h;
public:
    Foo(const Foo& f):h(f.h){}
    Foo(const HasPtr & Hp):h(Hp){}
    ~Foo()=default;
};
inline void swap(Foo& lhs , Foo& rhs){
    // using std::swap;//有没有这条语句都一样，因为重载函数参数匹配
    #ifndef NDEBUG
        std::cout<<"Foo swap"<<std::endl;
    #endif
    swap(lhs.h , rhs.h);
}
#endif