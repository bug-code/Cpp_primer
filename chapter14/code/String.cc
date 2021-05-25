#include "String.h"
std::allocator<char> String::alloc;

/*重载输出运算符  练习14.7 */
std::ostream& operator<<(std::ostream& os , const String& s){
    for (auto beg=s.element; beg!=s.cap; ++beg)
    {
        os<<*beg;
    }
    return os;
}

/*重载输入运算符*/
std::istream& operator>>(std::istream& is, String& s){
    char c;
    String tmp=s;
    while (is>>c)
    {
       if (!is)
        {
            s = tmp;
            break;
        }
        /*插入元素*/
        s.push_back(c);
    }
    return is;   
}
/*重载加法运算符*/
String operator+(const String& lhs, const String& rhs){
    auto tmp = lhs;
    for (auto beg = rhs.cbegin() , en = rhs.cend(); beg!=en; ++beg)
    {
        tmp.push_back(*beg);
    }
    return tmp;
}
/*相等运算符*/
bool operator==(const String& lhs,const String& rhs){
    bool flag = true;
    if (lhs.size() == rhs.size())
    {
        auto beg1 = lhs.cbegin() , beg2 = rhs.cbegin();
        for (size_t i = 0; i < lhs.size(); ++i)
        {
            if (*beg1++ != *beg2++)
            {
                flag=false;
                break;  
            }
        }
    }
    else
    {
        flag=false;
    }
    return flag;
}
/*不等运算符*/
bool operator!=(const String& lhs, const String& rhs){
    return !operator==(lhs , rhs);
}

/*关系运算符*/
bool operator<(const String& lhs , const String& rhs){
    for (auto beg1=lhs.cbegin() , bge2=rhs.cbegin() , en1 = lhs.cend() , en2=rhs.cend();beg1!=en1 && bge2!=en2 ; ++beg1 , ++bge2)
    {
        if (*beg1!=*bge2)
        {
            return *beg1<*bge2;
        }
    }
    return lhs.size()<rhs.size();
}


std::pair<char* , char*> String::alloc_n_copy(const char* b , const char* e){
    auto data = alloc.allocate(e-b);
    return {data , std::uninitialized_copy(b,e,data)};
}

/*扩大内存*/
void String::reallocate(unsigned int newcapacity){
    if (!newcapacity)//如果未指定重新分配多大的内存，则扩大两倍。指定的内存应大于cap
   {
        newcapacity = capacity()!=0 ? 2*capacity():1;
   }
   //分配新内存
   auto newdata = alloc.allocate(newcapacity);
   auto source = element;
   auto dest = newdata;
   for (size_t i = 0; i < size(); ++i)
   {
       alloc.construct(dest++ , *source++);
   }
   free();
   element=newdata;
   first_free=dest;
   cap=element+newcapacity;
}
/*判断是否有空余内存*/
void String::chk_n_alloc(){
    if (size()==capacity())
    {
        reallocate();   
    }
}


String::String(const char* c){
    auto datasize=strlen(c);
    auto newdata = alloc.allocate(datasize);
    element = newdata;
    first_free = newdata;
    cap=newdata+datasize;
    for (size_t i = 0; i < datasize; ++i)
    {
        alloc.construct(first_free++ , *c++);
    }
}

// 拷贝构造函数,类值行为
String::String(const String& s){
    auto pos=alloc_n_copy(s.element , s.first_free);
    element=pos.first;
    first_free=cap=pos.second;
    #ifndef NDEBUG
    std::cout<<"拷贝构造函数"<<std::endl;
    #endif
}
//移动构造函数
String::String(String &&s)noexcept:element(s.element) , first_free(s.first_free) ,cap(s.cap){
    s.element =s.first_free =s.cap = nullptr;
}

String& String::swap(String& s){
    std::swap(element , s.element);
    std::swap(first_free , s.first_free);
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
        first_free = v.first_free;
        cap = v.cap;
        v.element = v.first_free=v.cap = nullptr;
    }
    return *this;
}

/*插入元素*/
void String::push_back(const char& c){
    chk_n_alloc();
    alloc.construct(first_free++ , c);
}

void String::free(){
    if (element)
    {
        for (auto vptr = first_free; vptr!=element; )
        {
            alloc.destroy(--vptr);
        }
        alloc.deallocate(element , cap-element);
    }

}
String::~String(){
    free();
}
