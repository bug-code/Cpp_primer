#ifndef STRVEC
#define STRVEC
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>
class StrVec
{
    friend bool operator==(const StrVec& , const StrVec& );
    friend bool operator!=(const StrVec& , const StrVec& );
    friend bool operator<(const StrVec& , const StrVec&);
private:
    //类内静态对象声明
    static std::allocator<std::string> alloc;
    //真正的底层容器
    void reallocate(unsigned int newcapacity=0);
    void chk_n_alloc();
    std::pair<std::string* , std::string*> alloc_n_copy(const std::string* ,const std::string*);
    void free();
    //指向首元素
    std::string *elements;
    //指向第一个未初始化元素
    std::string *first_free;
    //容器实际容量
    std::string *cap;

public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){};
    StrVec(const std::initializer_list<std::string>& ilst);
    StrVec(const StrVec&);
    StrVec(StrVec &&)noexcept;
    StrVec& swap(StrVec&);
    StrVec& operator=(StrVec);
    StrVec& operator=(StrVec &&)noexcept;
    StrVec& operator=(const std::initializer_list<std::string>& ilst);
    /*练习14.26*/
    std::string& operator[](const size_t& n){ return elements[n];}
    const std::string& operator[](const size_t& n)const{return elements[n];}
    ~StrVec();
    void push_back(const std::string&);
    /*练习16.58*/
    template<typename ... Agrs> void emplace_back(Agrs&&... args);
    void pop_back();
    size_t size()const;
    size_t capacity()const;
    void reserve(const size_t& n);
    void resize(const size_t& , const std::string );
    std::string* begin();
    std::string* end();
    std::string* cbegin()const;
    std::string* cend()const;
};
#endif