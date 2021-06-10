#ifndef VEC_H
#define VEC_H
#include <memory>
#include <utility>
#include <initializer_list>
template<typename T> class Vec;
template<typename T> bool operator==(const Vec<T>& , const Vec<T>& );
template<typename T> bool operator!=(const Vec<T>& , const Vec<T>& );
template<typename T> bool operator<(const Vec<T>& , const Vec<T>& );

template<typename T> class Vec
{
    friend bool operator==<T>(const Vec<T>& , const Vec<T>&);
    friend bool operator!=<T>(const Vec<T>& , const Vec<T>& );
    friend bool operator< <T>(const Vec<T>& , const Vec<T>& );
private:
    //类内静态对象声明
    std::allocator<T> alloc;
    //新建内存,容器扩大
    void reallocate(unsigned int newcapacity=0 );
    //检查容器是否足够大
    void chk_n_alloc();
    //元素赋值到本容器
    std::pair<T* , T*> alloc_n_copy(const T* , const T*);
    //释放容器内存
    void free();
    //容器指针
    T* beg ;
    T* first_free ;
    T* cap;
public:
    Vec():beg(nullptr) , first_free(nullptr) , cap(nullptr) {}
    Vec(const std::initializer_list<T>& );
    //拷贝构造函数
    Vec(const Vec&);
    //移动构造
    Vec(Vec&&)noexcept;
    //交换
    Vec& swap(Vec&);
    //赋值运算符
    Vec& operator=(Vec);
    //移动赋值运算符
    Vec& operator=(Vec&&)noexcept;
    Vec& operator=(const std::initializer_list<T>& ilst);
    T& operator[](const size_t& n) {return beg[n];}
    const T& operator[](const size_t& n)const {return beg[n];}
    void push_back(const T&);
    /*练习16.58*/
    template<typename ... Args> void emplace_back(Args&& ... args);
    void pop_back();
    size_t size()const;
    size_t capacity()const;
    void reserve(const size_t& );
    /*添加元素，内存不足则扩大内存*/
    void resize(const size_t& , const T&);
    T* begin();
    T* end();
    const T* cbegin()const;
    const T* cend()const;
    ~Vec(){free();}
};

template<typename T> bool operator==(const Vec<T>& lhs, const Vec<T>& rhs){
    if (lhs.size()!=rhs.size())
    {
        return false;
    }
    else
    {
        for (auto beg1 = lhs.cbegin() , beg2 = rhs.cbegin() , en1 = lhs.cend() , en2 = rhs.cend(); 
            beg1 !=en1; ++beg1 , ++beg2)
        {
            if (*beg1 != *beg2 )
                return false;
        }
    }
    return true;
}
template<typename T> bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs){
    return !(lhs==rhs);
}
template<typename T> bool operator<(const Vec<T>& lhs , const Vec<T>& rhs){
    //先按元素顺序比较，再按容器大小比较
    for (auto beg1=lhs.cbegin() , beg2 = rhs.cbegin() , en1 = lhs.cend() , en2=rhs.cend(); beg1!=en1 && beg2!=en2; ++beg1 ,++beg2)
    {
        if (*beg1!=*beg2)
        {
            return *beg1 < *beg2;
        }
    }
    return lhs.size() < rhs.size();
}


template<typename T> void Vec<T>::reallocate(unsigned int newcapacity){
    /*
    1.内存扩大为原来的两倍
    2. 创建一个原来两倍大的内存
    3. 将旧址数据移动至新内存
    4. 释放旧内存
    5. 更新对象数据
    */
   if (!newcapacity)
   {
       newcapacity = capacity()%2 ? 2*capacity():1;
   }
   auto newdest = alloc.allocate(newcapacity);
   auto dest = newdest;
   auto tmpbeg = beg;
   for (size_t i = 0; i !=size(); ++i)
   {
       alloc.construct(dest++ , std::move(*tmpbeg++));
   }
   free();
   beg = newdest;
   first_free = dest;
   cap = beg+newcapacity;
}

template<typename T> void Vec<T>::chk_n_alloc(){
    if (size()==capacity())
        reallocate();
}

template<typename T> std::pair<T* , T*> Vec<T>::alloc_n_copy(const T* b, const T* ff){
    //分配一块范围内大小的内存
    auto data  = alloc.allocate(ff-b);
    /*写入元素，返回首尾指针*/
    return {data , std::uninitialized_copy(b , ff , data)};
}

template<typename T>  void Vec<T>::free(){
    //针对allocator类型的销毁，首先要逆序销毁其中的对象，再释放其内存、
    //不能传递给deallocate一个空指针
    if (beg)
    {
        //逆序析构对象
        for (auto p = first_free; p!=beg; )
            alloc.destroy(--p);//销毁对象，逆序
        alloc.deallocate(beg , cap-beg);//释放内存
    }
}

template<typename T> Vec<T>::Vec(const std::initializer_list<T>& ilst){
    //分配一块两倍ilst大小的内存
    auto datasize = 2*ilst.size();
    auto newdata = alloc.allocate(datasize);
    beg = first_free = newdata;
    cap = beg+datasize;
    for (auto beg = ilst.begin() , en = ilst.end(); beg!=en; ++beg)
    {
        alloc.construct(first_free++ , *beg) ; 
    }
}

template<typename T>    Vec<T>::Vec(const Vec& V){
    auto p = alloc_n_copy(V.cbegin() , V.cend());
    beg = p.first;
    first_free = p.second;
    cap = p.second;
}

template<typename T> Vec<T>::Vec(Vec&& V)noexcept:
beg(V.beg) , first_free(V.first_free) , cap(V.cap){
    V.beg = V.first_free = V.cap = nullptr;
}

//交换
template<typename T> Vec<T>& Vec<T>::swap(Vec& V){
    std::swap(beg , V.beg);
    std::swap(first_free , V.first_free);
    std::swap(cap , V.cap);
    return *this;
}

//赋值运算符
template<typename T> Vec<T>& Vec<T>::operator=( Vec V){
    this->swap(V);
    return *this;
}

//移动赋值运算符
template<typename T>  Vec<T>& Vec<T>::operator=(Vec&& V)noexcept{
    if (this!= &V)
    {
        beg = std::move(V.beg);
        first_free = std::move(V.first_free);
        cap = std::move(V.cap);
        V.beg = V.first_free = V.cap = nullptr;
    }
    return *this;
}


template<typename T> Vec<T>& Vec<T>::operator=(const std::initializer_list<T>& ilst){
    Vec V(ilst);
    beg = V.beg;
    first_free = V.first_free;
    cap = V.cap;
    return *this;
}
template<typename T> void Vec<T>::push_back(const T& t){
    chk_n_alloc();
    alloc.construct(first_free++ , t);
}

/*练习16.58*/
template<typename T> template<typename... Args> inline  void Vec<T>::emplace_back(Args&& ... args){
    chk_n_alloc();
    alloc.construct(first_free++ , std::forward<Args>(args)...);
}

template<typename T> void Vec<T>::pop_back(){
    if (first_free>beg)
    {
        alloc.destroy(--first_free);
    }
}
template<typename T>  size_t Vec<T>::size()const{
    return first_free-beg;
}
template<typename T> size_t Vec<T>::capacity()const{
    return cap-beg;
}
template<typename T> void Vec<T>::reserve(const size_t&  n){
    reallocate(n);
}
/*添加元素，内存不足则扩大内存*/
template<typename T> void Vec<T>::resize(const size_t& n , const T& t){//只保留n个元素，少则加，多则减
    //判断剩余内存是否足够
    if (n>capacity())
    {
        reallocate(n-capacity());
        while (first_free!=cap)
        {
            push_back(t);
        }
    }
    else if (n>size() && n<=capacity())
    {
        auto sz = n-size();
        while (sz--)
        {
            push_back(t);
        }
    }
    else
    {
        auto sz = size()-n;
        while (sz--)
        {
            pop_back();
        }
    }
}
template<typename T> T*  Vec<T>::begin(){
    return beg;
}
template<typename T> T* Vec<T>::end(){
    return first_free;
}
template<typename T> const T* Vec<T>::cbegin()const{
    return beg;
}
template<typename T> const T* Vec<T>::cend()const{
    return first_free;
}

#endif