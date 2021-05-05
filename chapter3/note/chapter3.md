# 字符串、向量和数组

## 命名空间using的声明
作用域操作符`::`
- 含义： 编译器应从操作符左侧名字所示的作用域中寻找右侧的那个名字
- `std::cout` 从`std`作用域空间寻找名字为`cout`的变量

**`using` 声明**
1. `using namespace::name`
   - 例如`using std::cin` , 之后直接可使用`cin` 
2. 一个`using`声明引入一个变量
3. 头文件中不应包含`using`声明

## 标准库类型string
```
#include <string> //标准库文件表示可变长的字符序列
using std::string ; /string 定义在std命名空间中
```
### string::size_type类型
```
string.size() //返回的是string::size_type类型，表示任意大小
string::size_type; //size_type是在string中定义的
```
### cctype头文件
`cctype`头文件处理string字符串中的字符
### 基于范围的for语句
```
for(declaretion:expression){
    statement;
}
```
**使用下标访问序列时要检查合法性，下表类型用size_type类型**

# 标准库容器vector（类模板）

**模板：** 模板本身不是类或函数，可以将模板看作为编译器生成类或函数编写的一份声明
`vector:` 表示类型相同对象的集合
- 使用
  ```
  #include <vector>
  using std::vector;
  ```
## vector初始化
**vector**初始化包括：
- ```vector<typr> vec(vec1)  , vector<type> vec(n,val) , vector<type> vec(n)``` 构造函数初始化
- ```vector<type> vec = vec1``` 拷贝初始化
- ```vector<type> vec{val1 ,val2,...}   vector<type> vec={val1 ,val2,...}``` 列表初始化

vector初始化时类型必须相同，否则当无法执行列表初始化后，编译器会尝试用默认值初始化vector对象。

```
vector<int> vec(10);//构造函数初始化，含有10个默认值
vector<int> vec{10};//列表初始化，含有1个初始值10
vector<string> vec{"hi"}; //列表初始化，只有一个初始值hi
vector<string> vec("hi");//错误，构造函数初始化不能使用字面值
vector<string> vec{10}; // 类型不同，编译器尝试使用构造函数初始化。含有10个默认初始化的值
vector<string> vec{10,"hi"}; //类型不同，编译器尝试使用构造函数初始化，含有10个hi
```

vector操作 | 含义 | 
---------|----------|
 v.empty() | 容器为空则为真，否则为假 | 
 v.size() | 返回容器大小 |
 v.push_back(t) | 容器尾端添加元素t |
|v[n] | 返回容器第n个位置上的元素引用|
|v1=v2|v2中元素拷贝给v1|
|v1={a,b,c,d,...}|列表中元素替换v1中元素|
|v1==v2 ， v1 != v2|判断v1与v2是否相等|
|< , > ,<= , => |字典顺序比较|

- **vector中要使用size_type类型，需指定由哪种类定义的**
```
vector<int>::size_type
```
- **vector对象与string对象下标运算符只能用于访问元素，而不能用于添加元素**

# 迭代器

迭代器所指对象是容器元素中或string对象中的字符，迭代器由无效和有效之分。

```
auto b=v.begin() , e=v.end();//可读写迭代器
auto cb=v.cbegin() , ce = v.cend();//只读迭代器
```
*尾迭代器指向尾元素下一位置*
## 迭代器类型
- iteration 可读写
- const_iteration 只读
```
vector<int>::iteration it; //可读写
vector<int>::const_iteration it; //只读
string::iteration it;
string::const_iteration;
```

迭代器操作 | 含义 | 
---------|----------|
 *iter | 返回迭代器所指元素引用 | 
 iter->mem | 解引用iter并获取改元素名为mem的成员 | 
 ++iter | 令迭代器指向容器的下一元素 |
 |--iter|令迭代器指向容器的上一元素|
 |iter1==iter2 , iter1 != iter2| 判断迭代器是否相等|

## 结合解引用和成员访问操作
```
(*iter).mem 与 iter->mem等价
*iter.mem //错误,iter为迭代器，没有mem元素
```