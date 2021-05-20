#include <cstring>
#include <memory>
#include <utility>
#include <algorithm>
#include <iostream>
class String
{
private:
    static std::allocator<char> alloc;
    std::pair<char* , char*> alloc_n_copy(const char*,const char*);
    char* element;
    // char* first_free;
    char* cap;
public:
    //默认构造函数
    String():element(nullptr) ,  cap(nullptr){};
    String(const char* );
    //拷贝构造函数
    String(const String&);
    //移动构造函数
    String(String &&)noexcept;
    size_t size()const;
    String& swap(String&);
    String& operator=(String );
    //移动赋值运算符
    String& operator=(String &&)noexcept;
    char* begin(){return element;}
    char* end(){return cap;}
    void free();
    ~String();
};

