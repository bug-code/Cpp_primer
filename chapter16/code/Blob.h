#ifndef BLOB_H
#define BLOB_H
#include <vector>
#include <memory>
#include <string>
/*类指针类型容器*/
template<typename T> class BlobPtr;
template<typename T> class Blob;
template<typename T> bool operator==(const Blob<T>&  , const Blob<T>& );
template<typename T> bool operator!= (const Blob<T>&  , const Blob<T>& );
template<typename T> bool operator<(const Blob<T>&  , const Blob<T>& );
template<typename T> class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob& , const Blob&);
    friend bool operator!=<T>(const Blob& , const Blob&);
    friend bool operator< <T>(const Blob& , const Blob&);
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_t  , const std::string&  )const;
public:
    /*返回模板类型声明 ， 十分重要,与模板类型参数相关的都要提前声明*/
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator; 

    Blob():data(std::make_shared<std::vector<T>>()) {}
    template<typename it> Blob(it b , it e):data(std::make_shared<std::vector<T>>(b,e)){ }
    //拷贝构造函数 , 类值拷贝
    Blob(const Blob& B):data(*B.data){}
    Blob(std::initializer_list<T> il):data(std::make_shared<std::vector<T>>(il)){};
    //拷贝赋值运算符，类指针类型
    Blob& operator=(const Blob&);
    T& operator[](const size_t& n){return *(data->begin()+n);}
    const T& operator[](const size_t& n)const{return *(data->cbegin()+n);}
    //获取大小
    size_type size()const { return data->size();}
    //判断是否为空
    bool empty()const{return data->empty();}
    //增删
    void push_back(const T& t){data->push_back(t);}
    void push_back(T&& t)noexcept{data->push_back(std::move(t));}
    void pop_back(){check(0 , "vessel is empty!") ;data->pop_back();}
    //元素访问
    T& front(){check(0,"vessle is empty!") ; return data->front();}
    const T& front()const{check(0,"vessle is empty"); return data->front();}
    T& back(){check(0,"vessle is empty!") ; return data->back();}
    const T& back()const{check(0,"vessle is empty"); return data->back();}
    iterator begin(){return data->begin();}
    iterator end(){return data->end();}
    const_iterator cbegin()const{return data->cbegin();}
    const_iterator cend()const{return data->cend();}
    ~Blob()=default;
};

template<typename T> Blob<T>& Blob<T>::operator=(const Blob& B){
    data(std::make_shared<vector<T>>(*B.data));
    return *this;
}
template<typename T> void Blob<T>::check(size_t i , const std::string& msg )const{
    if(i>=data->size())
        throw std::out_of_range(msg);
}
template<typename T> bool operator==(const Blob<T>& lhs , const Blob<T>& rhs){
    if (lhs.size()!=rhs.size()) return false;
    for (auto beg1 = lhs.cbegin() , beg2 = rhs.cbegin() , en1=lhs.cend() , en2=rhs.cend(); beg1!=en1&&beg2!=en2; ++beg1,++beg2)
    {
        if (*beg1!=*beg2)
            return false;
    }
    
    return true;
}
template<typename T> bool operator!=(const Blob<T>&  lhs, const Blob<T>& rhs){
    return !(lhs==rhs);
}
template<typename T> bool operator<(const Blob<T>& lhs , const Blob<T>& rhs){
        for (auto beg1 = lhs.cbegin() , beg2 = rhs.cbegin() ,  en1 = lhs.cend() , en2 = rhs.cend(); 
            beg1 != en1 && beg2 != en2; ++beg1 , ++beg2)
        {
            if (*beg1!=*beg2)
                return *beg1 < *beg2 ;
        }
        return lhs.size() < rhs.size();
}
#endif