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
private:
    shared_ptr<vector<string>> data;
    void check(vector<string>::size_type i,const string &msg) const;
public:
    StrBlob():data(make_shared<vector<string>>()){}
    StrBlob(const StrBlob &SB ):data(SB.data){}
    /*可变形参initializer_list<string> il*/
    StrBlob(initializer_list<string> il);
    /*获取对象大小*/
    vector<string>::size_type size() const {return data->size(); }
    /*判断对象是否为空*/
    bool empty() const{return data->empty();}
    /*添加删除元素*/
    void push_back(const string &s){data->push_back(s);}
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