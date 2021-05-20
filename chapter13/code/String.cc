#include "String.h"
std::allocator<char> String::alloc;

std::pair<char* , char*> String::alloc_n_copy(const char* b , const char* e){
    auto data = alloc.allocate(e-b);
    return {data , std::uninitialized_copy(b,e,data)};
}


String::String(const char* c){
    auto datasize=strlen(c);
    auto newdata = alloc.allocate(datasize);
    element = newdata;
    cap=newdata;
    for (size_t i = 0; i < datasize; ++i)
    {
        alloc.construct(cap++ , *c++);
    }
}

// 拷贝构造函数,类值行为
String::String(const String& s){
    auto pos=alloc_n_copy(s.element , s.cap);
    element=pos.first;
    cap=pos.second;
    #ifndef NDEBUG
    std::cout<<"拷贝构造函数"<<std::endl;
    #endif
}
//移动构造函数
String::String(String &&s)noexcept:element(s.element) , cap(s.cap){
    s.element = s.cap = nullptr;
}

size_t String::size()const{
    return cap-element;
}




String& String::swap(String& s){
    std::swap(element , s.element);
    std::swap(cap , s.cap);
    return *this;
}
String& String::operator=(String s){
    this->swap(s);
    #ifndef NDEBUG
    return *this;
    #endif
}

//移动赋值运算符
String& String::operator=(String&& v)noexcept{
    if (this!= &v)
    {
        element=v.element;
        cap = v.cap;
        v.element = v.cap = nullptr;
    }
    return *this;
}

void String::free(){
    if (element)
    {
        for (auto vptr = cap; vptr!=element; )
        {
            alloc.destroy(--vptr);
        }
        alloc.deallocate(element , cap-element);
    }

}
String::~String(){
    free();
}
