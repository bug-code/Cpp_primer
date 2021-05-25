#include "StrVec.h"
//类外静态对象定义
std::allocator<std::string> StrVec::alloc;


/*public*/
//练习13.40
StrVec::StrVec(const std::initializer_list<std::string>& ilst){
    //分配一块两倍ilst大小的内存
    auto datasize = ilst.size()*2;
    auto newdata=alloc.allocate(datasize);
    elements = first_free=newdata;
    cap = elements+datasize;
    //添加元素
    for (auto beg = ilst.begin() , en = ilst.end(); beg!=en;++beg)
    {
        alloc.construct(first_free++ , *beg);
    }
}

//拷贝构造函数
StrVec::StrVec(const StrVec& SV){
    auto pos = alloc_n_copy(SV.cbegin() , SV.cend());
    elements = pos.first;
    first_free=pos.second;
    cap=pos.second;
}

//移动构造函数
StrVec::StrVec(StrVec &&v)noexcept:elements(v.elements)
,first_free(v.first_free) , cap(v.cap){
    v.elements=v.first_free=v.cap=nullptr;
}

//交换函数
StrVec& StrVec::swap(StrVec& SV){
    std::swap(elements , SV.elements);
    std::swap(first_free , SV.first_free);
    std::swap(cap,SV.cap);
    return *this;
}
// 拷贝赋值运算符
StrVec& StrVec::operator=(StrVec SV){
    this->swap(SV);
    return *this;
}
//移动赋值运算符
StrVec& StrVec::operator=(StrVec &&v)noexcept{
    if (this != &v) //两个地址不同，则不是同一块内存
    {
        //析构本对象，释放本对象内存
        elements = v.elements;
        first_free = v.first_free;
        cap=v.cap;
        v.elements=v.first_free=v.cap=nullptr;
    }
    return *this;
}

//析构函数
StrVec::~StrVec(){
    free();
}
//接口
void StrVec::push_back(const std::string& s){
    chk_n_alloc();
    alloc.construct(first_free++ ,s );
}

void StrVec::pop_back(){
    if (first_free > elements)
    {
        alloc.destroy(--first_free);//析构对象
        // alloc.deallocate(first_free , 1);//释放内存
    }
}

size_t StrVec::size()const{
    return first_free-elements;
}

void StrVec::reserve(const size_t& n){
    reallocate(n);
}

void StrVec::resize(const size_t& n ,const std::string s){//针对的是元素数量，而不是容量
    //若n大于cap,添加内存，同时要添加元素
    if (n>capacity())
    {
        //增加需要的内存
        reallocate(n-capacity());
        //从first_free到cap初始化为s
        while (first_free!=cap)
        {
            push_back(s);
        }
    }
    else if ( n >size() && n<=capacity() )//内存足够
    {
        while (n-size())
        {
            push_back(s);
        }
    }
    else
    {
        while (size()-n)
        {
            pop_back();
        }
    }
}

size_t StrVec::capacity()const{
   return  cap-elements;
}

const std::string* StrVec::cbegin()const{
     
    return elements;
}
const std::string* StrVec::cend()const{

    return first_free;
}

std::string* StrVec::begin(){
    auto elem = elements;
    return elem;
}
std::string* StrVec::end(){
    auto ff=first_free;
    return ff;
}

/*private*/
void StrVec::reallocate(unsigned int newcapacity){
    /*
    1. 内存扩大为原来的两倍
    2. 创建一个原来两倍大的内存
    3. 将旧址数据移动至新内存
    4. 释放旧内存
    5. 更新对象数据
    */
   //1.
   if (!newcapacity)//如果未指定重新分配多大的内存，则扩大两倍。指定的内存应大于cap
   {
        newcapacity = capacity()%2? 2*capacity():1;
   }
   //2.
   auto newdest = alloc.allocate(newcapacity);
   //3.
   auto dest = newdest;
   auto elem = elements;
   for (size_t i = 0; i < size(); ++i)
       alloc.construct(dest++ , std::move(*elem++));
    //4.
    free();
    elements = newdest;
    first_free = dest;
    cap = elements+newcapacity;
}

void StrVec::chk_n_alloc(){
    if (size()==capacity()) 
        reallocate();    
}

std::pair<std::string* , std::string*> 
StrVec::alloc_n_copy(const std::string* b , const std::string* e){
    //分配一块范围内大小的内存
    auto data = alloc.allocate(e-b);
    //返回首尾元素
    //data表示首地址 ， uninitialized_copy表示拷贝范围内的元素到首地址位置的内存
    return {data , std::uninitialized_copy(b , e , data)};
}

void StrVec::free(){
    //针对allocator类型的销毁，首先要逆序销毁其中的对象，再释放其内存
    //不能传递给deallocate一个空指针
    if (elements)
    {
        //逆序析构对象
        // for (auto p = first_free; p!=elements; )
        //     alloc.destroy(--p);
        //练习13.43
        std::for_each(  elements ,first_free , [this](std::string& s){ alloc.destroy(&s); } );
        alloc.deallocate(elements , cap-elements); 
    }
}