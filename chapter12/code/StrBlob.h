#ifndef STRBLOB
#define STRBLOB
#include <string>
#include <vector>
#include <memory>
using namespace std;
class StrBlobPtr;
class ConstStrBlobptr;
class StrBlob
{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    friend bool operator==(const StrBlob& , const StrBlob&);
    friend bool operator!=(const StrBlob& , const StrBlob&);
    friend bool operator<(const StrBlob& , const StrBlob&);
private:
    shared_ptr<vector<string>> data;
    void check(vector<string>::size_type i,const string &msg) const;
public:
    StrBlob():data(make_shared<vector<string>>()){}
    /*练习13.25，类值版本*/
    StrBlob(const StrBlob& SB):
    data(make_shared<vector<string>>(*SB.data)){}
    // /*类指针版本*/
    // StrBlob(const StrBlob &SB ){data=SB.data;}
    /*可变形参initializer_list<string> il*/
    StrBlob(initializer_list<string> il);
    /*拷贝赋值运算符*/
    StrBlob& operator=(const StrBlob&);
    /*下标运算符 练习14.26*/
    string& operator[](const size_t& n){return *(data->begin()+n);}
    const string& operator[](const size_t& n)const{return *(data->cbegin()+n);}
    /*获取对象大小*/
    vector<string>::size_type size() const {return data->size(); }
    /*判断对象是否为空*/
    bool empty() const{return data->empty();}
    /*添加删除元素*/
    void push_back(const string &s){data->push_back(s);}
    void push_back(string &&s){data->push_back(std::move(s));}
    void pop_back();
    /*元素访问*/
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;
    vector<string>::iterator begin();
    vector<string>::iterator end();
    vector<string>::const_iterator cbegin();
    vector<string>::const_iterator cend();
    ~StrBlob()=default;
};

#endif