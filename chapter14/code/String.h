#include <cstring>
#include <memory>
#include <utility>
#include <algorithm>
#include <iostream>
class String
{
    /*重载输出运算符*/
    friend std::ostream& operator<<(std::ostream&, const String &);
    /*重载输入运算符*/
    friend std::istream& operator>>(std::istream& , String&);
    /*重载加法运算符*/
    friend String operator+(const String& , const String& );
    /*相等运算符*/
    friend bool operator==(const String & ,const String&);
    /*不等运算符*/
    friend bool operator!=(const String& , const String&);
    /*关系运算符`<`*/
    friend bool operator<(const String& , const String&);
private:
    static std::allocator<char> alloc;
    std::pair<char* , char*> alloc_n_copy(const char*,const char*);
    /*扩大内存*/
    void reallocate(unsigned int newcapacity=0);
    /*判断是否有空余内存*/
    void chk_n_alloc();
    char* element;
    char* first_free;
    char* cap;
public:
    //默认构造函数
    String():element(nullptr) , first_free(nullptr), cap(nullptr){};
    String(const char* );
    //拷贝构造函数
    String(const String&);
    //移动构造函数
    String(String &&)noexcept;
    size_t size()const{return first_free-element;};
    size_t capacity()const{return cap-element;}
    String& swap(String&);
    String& operator=(String );
    //移动赋值运算符
    String& operator=(String &&)noexcept;
    /*下标运算符 练习14.26*/
    char& operator[](const size_t& n){return element[n];}
    const char& operator[](const size_t& n)const{return element[n];}
    
    void push_back(const char&);
    char* cbegin()const{return element;}
    char* begin(){return element;}
    char* cend()const{return first_free;}
    char* end(){return first_free;}
    void free();
    ~String();
};

