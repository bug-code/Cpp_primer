#include "StrBlob.h"
#include "StrBlobPtr.h"

/*重载相等运算符*/
bool operator==(const StrBlob& lhs, const StrBlob& rhs){
    bool flag = true;
    if ( lhs.data.get() != rhs.data.get() )
    {   
        flag=false;
    }
    else{
        if (lhs.data->size() != rhs.data->size())
        {
            flag=false;
        }
        else
        {
            auto beg1 = lhs.data->cbegin() , beg2=rhs.data->cend();
            for (size_t i = 0; i < lhs.data->size(); ++i)
            {
                if (*beg1++ != *beg2++)
                {
                    flag=false;
                    break;
                }
                
            }
        }
    }
    return flag;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs){
    return !operator==(lhs , rhs);
}

bool operator<(const StrBlob& lhs , const StrBlob& rhs){
    for (auto beg1  = lhs.data->cbegin() , beg2 = rhs.data->cbegin() , en1 = lhs.data->cend()  , en2  = rhs.data->cend(); beg1!=en1&&beg2!=en2; ++beg1 , ++beg2)
    {
        if (*beg1!=*beg2)
        {
            return *beg1<*beg2;
        }
    }
    return lhs.size()<rhs.size();
}

inline StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}
inline void StrBlob::check(vector<string>::size_type i , const string &msg)const{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}
inline void StrBlob::pop_back(){
    check(0 , "StrBlob is empty");
    data->pop_back();
}

inline string& StrBlob::front(){
    check(0 , "StrBlob is empty");
    return data->front();
}
/*左侧表示底层对象不可修改，右侧const必须存在，因为只有const对象才能调用const函数，返回常量*/
inline const string& StrBlob::front()const{
    check(0 , "StrBlob is empty");
    return data->front();
}
inline string& StrBlob::back(){
    check(0 , "StrBlob is empty");
    return data->back();
}
inline const string& StrBlob::back()const{
    check(0 , "StrBlob is empty");
    return data->back();
}
//非常量引用初始值必须为左值 不能使用StrBlobPtr&，因为StrBlobPtr(*this)为右值
inline vector<string>::iterator StrBlob::begin(){
    return data->begin();
}
inline vector<string>::iterator StrBlob::end(){
    return data->end();
}
inline vector<string>::const_iterator StrBlob::cbegin(){
    return data->cbegin();
}
inline vector<string>::const_iterator StrBlob::cend(){
    return data->cend();
}
inline StrBlob& StrBlob::operator=(const StrBlob& SB){
    data=make_shared<vector<string>>(*SB.data);
    return *this;
}