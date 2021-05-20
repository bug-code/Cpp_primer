#include "HasPtr.h"
#include <iostream>
// HasPtr& HasPtr::operator=(const HasPtr& Hp){
//     ps=Hp.ps;
//     i=Hp.i;
// }
/*类值行为HasPtr赋值运算符*/
// HasPtr& HasPtr::operator=(const HasPtr& HP){
//     auto tmp = new string(*HP.ps);;
//     delete ps;
//     ps=tmp;
//     i = HP.i;
//     return *this;
// }
/*类指针行为赋值运算符*/
HasPtr& HasPtr::swap( HasPtr& rhs){
    #ifndef NDEBUG
    std::cout<<"HasPtr 版本的swap."<<std::endl;
    std::cout<<"交换前："<<ps<<" "<<*rhs.ps<<std::endl;
    #endif
    std::swap(ps , rhs.ps);
    std::swap(i , rhs.i);
    std::swap(use , rhs.use);
    #ifndef NDEBUG
    std::cout<<"交换后："<<ps<<" "<<*rhs.ps<<std::endl;
    #endif
    return *this;
}

HasPtr::HasPtr(HasPtr&& hp)noexcept:ps(hp.ps),i(hp.i),use(hp.use){
    hp.ps = nullptr;
    hp.use = nullptr;
}

HasPtr& HasPtr::operator=( HasPtr HP){
    ++*HP.use;
    if (!--*use)
    {
        delete ps;
        delete use;
    }
    // ps=HP.ps;
    // i=HP.i;
    // use=HP.use;
    this->swap(HP);
    return *this;
}
// HasPtr& HasPtr::operator=(HasPtr&& hp)noexcept{
//     if (this!=&hp)
//     {
//         ps=hp.ps;
//         use=hp.use;
//         i =hp.i;
//         hp.ps=nullptr;
//         hp.use=nullptr;
//     }
//     return *this;
// }

bool HasPtr::operator<(const HasPtr& Hp){
    return i<Hp.i;
}


HasPtr::~HasPtr(){
    if (!--*use)
    {
        delete ps;
        delete use;
    }
}
