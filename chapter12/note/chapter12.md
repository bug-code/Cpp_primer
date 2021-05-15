# 动态内存
内存管理：

- **静态内存：** 保存局部static对象、类static数据成员、定义在任何函数之外的变量。（程序结束时销毁）
- **栈内存：** 保存定义在函数内的非static对象（函数结束时销毁）
- **堆内存：** 每个程序有一个内存池，程序用堆来存储**动态分配**的对象。当动态对象不使用时，必须显式销毁。

**note:** 正确的管理动态内存时非常棘手的

## 动态内存和智能指针
动态内存的管理时通过一对运算符来完成的：

- **new:** 在**动态内存**中为对象分配空间并返回一个指向该对象的指针，可以进行对象初始化。
- **delete:** 接受一个**动态对象**的指针，销毁该对象，并释放与之关联的内存

**内存泄漏：** 没有及时释放无用内存
**指针非法访问：** 提前释放了还在使用的数据对象

**智能指针：** 头文件 **`<memory>`**
    行为类似常规指针，，区别在于自动释放指向的对象

-  **shared_ptr:** 允许多个指针指向同一个对象
-  **unique_ptr：** **独占**所指对象
- **weak_ptr:** **伴随类**，弱引用，指向share_ptr管理的对象

### share_ptr类
智能指针也是模板。创建智能指针时，需提供指针可以指向的类型。

**share_ptr和unique_ptr都支持的操作**

操作 | 含义 
---------|----------
share_ptr\<T\> sp; | 空指针，指向类型为T的对象 
unique_ptr\<T\> up;| 同上 
p | 将p用作一个条件判断，若p指向一个对象，则为true
*p| 解引用p,获得它指向的对象
p->mem| 等价于(*p).mem
p.get()| 返回p中保存的指针。当智能指针释放了其对象，返回的指针所指向的对象也就消失了
swap(p,q)|交换p和q中的指针
p.swap(q)|同上

**shared_ptr独有的操作**

操作 | 含义 
---------|----------
make_shared\<T\>(args) | 返回一个shared_ptr，指向一个动态分配的类型为T的对象，使用args初始化此对象 
shared_ptr\<T\> p(q) | p是shared_ptr的拷贝，此操作会递增q中的计数器。q中的指针必须能转换为T*（隐式转换） 
p=q |p和q都是shared_ptr,所保存的指针必须能相互转换。此操作会递减p的引用计数，递增q的引用计数；若p的引用计数变为0,则将其管理的原内存释放
p.unique()| 若p.use_count为1，返回true,否则返回false
p.use_count()| 返回与p共享对象的智能指针数量；可能很慢，主要用于测试

#### make_shared函数
make_shared也在头文件 **\<momery\>** 中。
**最安全的分配和使用动态内存的方法是调用make_shared标准库函数**

**示例：**
```
shared_ptr<int> p1 = make_shared<int>(42);
shared_ptr<string> p2 = make_shared<string>(10,'9');
auto p3 = make_shared<int>(); //默认初始化
```
#### shared_ptr的拷贝和赋值
当进行拷贝或赋值时，每个shared_ptr都有一个关联的计数器（**引用计数**），记录有多少个其他shared_ptr指向相同的对象。

**一旦一个shared_ptr的计数器变为0，它就会自动释放自己所管理的对象。**

**示例：**
```
auto r = make_share<int> (42);
r=q;
/*
1. 给r赋值，令它指向另一个地址
2. 递增q指向的对象的引用计数
3. 递减r原来指向的对象引用操作
4. r原来指向的对象已没有引用者，自动释放内存
5. r中引用计数等于q中引用计数
*/
```
**到底是用一个计数器还是其他数据结构记录有多少指针共享对象，完全由标准库的具体实现决定。**

#### shared_ptr自动销毁所管理的对象
当指向一个对象的最后一个shared_ptr被销毁时，shared_ptr类会通过**析构函数**自动销毁此对象。

shared_ptr的析构函数会递减它所指向的对象的引用计数。如果引用计数为0，则shared_ptr的析构函数销毁对象，释放占用的内存。

#### shared_ptr还会自动释放相关联的内存
返回shared_ptr指针的函数：
```
shared_ptr<Foo> faactory(T args){
    return make_shared<Foo> (args);
}
```
由于在最后一个shared_ptr销毁前内存都不会释放，保证shared_ptr在无用之后不再保留就非常重要。
**如果将shared_ptr存放在一个容器中，而后不再需要全部元素，而只使用其中一部分，要记得用erase删除不再需要的元素。**

#### 使用了动态生存周期的资源的类
**程序使用动态内存出与以下三种原因之一：**
1. 程序不知道自己需要使用多少对象
2. 程序不知道所需对象的准确类型
3. 程序需要在多个对象间共享数据

#### 定义StrBlob类
当拷贝一个Blob对象时，原Blob对象及其拷贝应该引用相同的底层元素。
**多个对象共享数据——>动态内存——>shared_ptr指针**

#### StrBlob的拷贝、赋值和销毁
StrBlob对象底层是一个指向`vector<string>`类型的`shared_ptr`指针。遵循shared_ptr指针的规范。

### 直接管理内存
头文件`<new>` , 头文件`<delete>`
- **运算符new** 分配内存
- **运算符delete** 释放new分配的内存

**自己直接管理内存的类不能依赖类对象拷贝、赋值、销毁操作的任何默认定义**
#### 使用new动态分配和初始化对象
在堆内存中分配的内存是**无名**的，因此new无法为其分配对象命名，而是返回一个指针。
**示例：**
```
//p1指向动态分配的，未初始化的无名对象
int *p1= new int; 
int *p2=new int(666);
string *ps = new string(10,'8');
vector<int> *pv = new vector<int>{0,1,2,3,4,5};
```
可以对动态分配的对象进行值初始化，只需在类型名之后加一对空括号即可。
```
int *p1 = new int; //值未定义
int *p2 = new int(); //值默认初始化为0
```
**new中有（）表示值初始化 ，没有则表示值未定义。两者有本质的区别**
**在动态分配的对象定义时最好进行值初始化**

可以使用**auto**从括号中的初始化器中推断对象类型，但括号中只能有一个初始化器。
```
auto p1=new auto(obj);//正确
auto p2 = new auto{a,b,c};//错误，只能有一个初始化器
auto p3 = new auto{a};//正确，待测试
```
#### 动态分配的const对象
动态分配的const对象必须进行值初始化。未定义默认构造函数的类，必须进行值初始化。
```
const int* pci = new const int(1024);//正确
const int* pci = new const int();//正确
const int* pci = new const int;//错误，未进行值初始化
```
#### 内存耗尽
默认情况下，如果new不能分配所要求的内存空间，则会抛出一个类型为bad_alloc的异常。可以改变使用new的方式来阻止抛出异常。
```
int *p1 = new int;//如果分配失败，new抛出是std::bad_alloc
/*如果分配失败，new返回一个空指针*/
int *p2 = new (nothrow) int;//定位new，通常用于调试
```
bad_alloc和nothrow定义在头文件`<new>`中。

#### 释放动态内存
通过
**`delete 表达式`** 将动态内存归还系统。
`delete`表达式接受一个指针。
1. 销毁给定指针指向的对象
2. 释放对应的内存

```
delete p;//p必须指向一个new分配的对象或一个空指针
```
#### 指针值和delete
delete一块非new分配的内存，或将相同的指针值释放多次，其行为未定义。
#### 动态对象的生存周期直到被释放时为止
由内置指针管理的动态内存在被显式释放前一直都会存在。
**示例：**
```
//函数返回指针，指针指向动态分配的对象
Foo* factory(T arg){
    return new Foo(arg);
}
void use_factory(arg){
    Foo* p = factory(arg);//使用了p但没有delete它
}
//程序离开作用域，局部变量指针p被销毁，但是p指向的对象是动态分配的内存，没有delete,则这块内存将会一直存在（内存泄漏）。添加delete p;语句
```
**使用new和delete管理动态内存存在三个常见的问题：**
1. 忘记delet动态分配的内存。（内存泄漏）
2. 使用已经释放掉的对象。
3. 同一块内存释放多次。当多次释放动态内存时，自由空间可能被破坏。

#### delete后重置指针值
**悬空指针：** 指向一块曾经保存数据对象但现在已经无效的内存的指针。
当delete一个指针后，指针值就变为无效了。
**虽然指针已经无效，但在很多机器上指针仍然保存着（已经释放了的）动态内存的地址**
#### 这只是提供了有限的保护
当多个指针指向相同的内存，在delete内存之后重置指针的方法只针对这个指针有效。对其他任何仍指向（已释放的）内存的指针是没有作用的。
```
int *p(new int(42));//p指向动态内存
auto q=p;//q和p指向相同的内存
delete p;//指针p被销毁，成为悬空指针
p=nullptr;//指出p不再指向任何对象
//但是q也成为了悬空指针
```
### shared_ptr和new结合使用
可以使用new返回的指针来初始化智能指针。
```
shared_ptr<double> p1;//未初始化，空指针
shared_ptr<int> p2(new int(42));//p2进行了初始化
shared_ptr<int> p1 = new int(1024);//错误，必须使用直接初始化
```
接受指针参数的智能指针构造函数是explicit的，即不能进行隐式转换，必须直接初始化。
```
shared_ptr<int> clone(int p){
    return new int(p);//错误，不能将内置指针隐式转换为智能指针
}
```
**定义和改变shared_ptr的其他方法**

操作 | 含义
---------|----------
sahred_ptr\<T\> p(q)| p管理内置指针q所指向的对象；q必须指向new分配的内存，且能够转换为T*类型 
shared_ptr\<T\> p(u)  |p从unique_ptr u那里接管了对象的所有权；将u置为空 
shared_ptr\<T\> p(q,d) | p接管了内置指针q所指向的对象的所有权。q必须能转换为T*类型。p将使用可调用对象d来代替delete。
shared_ptr\<T\> p(p2,d)| p是shared_ptr的拷贝，唯一的区别是p将用可调用对象d来替代delete
p.reset()|若p是唯一指向其对象的shared_ptr，reset会释放此对象。若传递了可选的参数内置指针q，会令p指向q，否则会将p置空。若还传递了参数d，将会调用d而不是delete来释放p
p.reset(q)|同上
p.reset(q,d)|同上

#### 不要混合使用普通指针和智能指针
将一个shared_ptr绑定到一个普通指针时，我们就将内存的管理交给了这个shared_ptr。一旦这样做了，我们就不应该再使用内置指针来访问shared_ptr这个所指向的内存了。
#### 也不要使用get初始化另一个智能指针或为智能指针赋值
智能指针类型定义了一个名为get的函数，它返回一个内置指针，指向智能指针管理的对象。
**这样设计是为了：**
需要向不能使用智能指针的代码传递一个内置指针。**使用get返回指针的代码不能delete此指针。**

**示例：**
```
shared_ptr<int> p(new int(42));//引用计数为1
int *q=p.get();//正确，但是使用q时要注意，不要让它管理的指针被释放。q为内置指针，指向动态内存
{//新程序块
    //两个独立的shared_ptr指向相同的内存
    auto tmp=shared_ptr<int>(q);//局部智能指针,tmp , q,p指向同一块动态内存
}//程序块结束，tmp被销毁，tmp所指向的内存被释放
int foo = *p;//未定义，p成为了悬空指针
```
get用来将指针的访问权限传递给代码；只有在确定代码不会delete指针的情况下，才能使用get。

**永远不要用get初始化另一个智能指针或者为另一个智能指针赋值。**
**因为：** p1.get()获取是p1智能指针所指向的动态内存的**内置指针**。当该**内置指针初始化**另一个智能指针p2时，相当于创建了两个指向该动态内存的智能指针群，指针群p1和指针群p2。当指针群p2计数器为0时，其动态内存会被销毁。如果这时要使用p1则产生未定义结果。

#### shared_ptr操作
与赋值类似，reset会更新引用计数，如果需要的话，会释放掉p指向的对象。
**在改变底层对象之前，先要检查自己是否是当前对象仅有的用户。如果不是，在改变之前制作一份新的拷贝。**

**示例：**
```
if(!p.unique())//如果不是唯一，则要做一份拷贝。否则会影响其他智能指针的正常工作
    p.reset(new string(*p));//制作一份拷贝
++*p;//现在直到自己是唯一的用户，可以改变对象的值。
```
### 智能指针和异常
当发生异常时，我们直接管理的内存是不会自动释放的，如果私用内置指针管理内存，且在new之后在对应的delete之前发生了异常，则内存不会被释放；
**示例：**
```
void f(){
    int *ip =new int(42);//动态分配一个新对象
    //<-在这代码抛出一个异常，且在f中未被捕获
    delete ip;//则此段代码不会执行，ip指向的动态内存不会被释放，造成内存泄漏。
}
```
#### **智能指针和哑类**
如果类没有定义析构函数来释放对象使用的资源，可能会遇到和使用动态内存相同的错误。
1. 忘记释放资源
2. 资源分配和释放之前发生异常，程序发生资源泄漏。
   
可以使用shared_ptr来解决

#### **使用自定义的释放操作**
可以自定义一个函数 **(删除器)** 来替代delete。这个删除器哈桑农户必须能完成对shared_ptr中保存的指针进行释放操作。
**示例：**
```
void end_connection(connection *p){
    disconnect(*p);
}//自定义删除函数
void f(destination &d){
    connection c = connect(&d);
    shared_ptr<connection> p(&c , end_connection);//向指针传递删除器
}
```
**note:**
正确使用智能指针，基本规范：
1. 不适用相同的内置指针值初始化（或reset）多个智能指针
2. 不使用delete get()返回的指针
3. 不适用get()初始化或reset另一个智能指针
4. 如果使用get()返回的指针，当最后一个对应的智能指针被销毁后，指针就变无效了。
5. 如果使用智能指针管理的资源不是new分配的内存，记得传递一个删除器。

### unique_ptr
1. 某个时刻只能有一个unique_ptr指向一个给定对象
2. 定义一个unique_ptr时，需要将其绑定到一个new返回的指针。初始化unique_ptr必须采用直接初始化形式
3. 由于一个unique_ptr只能独享其指向的对象，因此unique_ptr不支持普通的拷贝和赋值操作

```
unique_ptr<string> p1(new string("hey fuck you"));
unique_ptr<string> p2(p1);//错误，unique_ptr不支持拷贝
unique_ptr<strinh> p3;
p3=p2;//错误，unique_ptr不支持赋值
```
unique操作
操作 | 含义 
---------|----------
unique_ptr\<T\> u1| 空unique_ptr，可以指向类型为T的对象。u1会使用delete来释放它的指针；u2会使用一个类型为D的可调用对象来释放它的指针 
unique_ptr\<T，D\> u1 | 同上 
unique_ptr\<T,D\> u(d) | 空unique_ptr，指向类型为T的对象，用类型为D的对象d代替delete
u=nullptr|释放u指向的对象，将u置为空。**释放指针和内存**
u.release()|u放弃对指针的控制权，返回指针，并将u置为空**释放指针**
u.reset()| 释放u指向的对象**释放内存**
u.reset(q)|如果提供了内置指针q，令u指向这个对象；否则将u置位空
u.reset(nullptr)|重置为空

**unique_ptr指针转移示例：**
```
//将所有权从p1转移给p2
unique_ptr<string> p2(p1.release());//release将p1置为空
unique_ptr<string> p3(new string("fuck"));
p2.reset(p3.release());//reset释放了p2原来指向的内存
```
**调用release会切断unique_ptr和它原来管理的对象间的联系**
**如果不用另一个智能指针保存release返回的指针，程序要负责释放资源**
```
p2.release();//错误，p2不会释放内存，而且丢失了指针
auto p = p2.release();//正确，但需记得不用时释放内存
......
delete p;
```
#### 传递unique_ptr参数和返回unique_ptr
不能拷贝unique_ptr的规则有一个例外：**可以拷贝或赋值一个将要被销毁的unique_ptr**
**示例：**
```
unique_ptr<int> clone(int p){
    return unique_ptr<int> (new int(p));
}
unique_ptr<int> clone(int p){
    unique_ptr<int> ret(new int(p))
    return ret;
}
```
#### 向unique_ptr传递删除器
可以重载一个unique_ptr中默认的删除器。
1. 必须在尖括号中unique_ptr指向类型之后提供删除器类型（**函数指针类型**）
2. 在创建或reset一个这种unique_ptr类型的对象时，必须提供一个指定类型的可调用对象(删除器)。

```
//p指向一个类型为objT对象，并使用一个类型为objT的对象释放objT对象
//p会调用名为fcn的删除器。fcn为函数指针
unique_ptr<objT,delT> p(new objT,fcn);
```
### weak_ptr
weak_ptr弱共享指针。weak_ptr的使用不能脱离shared_ptr。weak_ptr是shared_ptr的伴随类。    所以练习12.20不能只用StrBlobPtr类来存储。
1. 是一种不控制所指对象生存周期的智能指针，它指向一个由一个shared_ptr管理的对象。
2. 将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数
3. 一旦最后一个shared_ptr被销毁，即使有weak_ptr指向对象，动态内存也会被释放

**weak_ptr操作**
操作|含义
---------|----------
weak_ptr\<T\> w| 空weak_ptr可以指向类型为T的对象 
weak_ptr\<T\> w(sp) | 与shared_ptr指向相同对象的weak_ptr。T必须能转换为sp指向的类型 
w=p | p可以是一个shared_ptr或一个weak_ptr。赋值后w与p共享对象 
w.reset() | 将w置空 
w.use_count()|与w共享的shared_ptr的数量
w.expired()|若w.use_count()为0，则返回true,否则返回false
w.lock()|如果expired为true,返回一个空的shared_ptr；否则返回一个指向w的对象的shared_ptr

**由于对象可能不存在，不能使用weak_ptr直接访问对象。而必须调用lock**
```
if(shared_tr<int> np=wp.lock()){
    //执行代码
}
```
#### 核查指针类
可以使用weak_ptr为自定义类定义一个伴随指针类。
## 动态数组
**一次为多个对象分配内存的功能**（一次分配一个对象数组的方法）：
1. 一种new表达式语法，可以分配并初始化一个对象数组
2. 一个名为allocator的累，允许将分配和初始化分离
**区别：**
1. new将内存分配和对象构造组合在一起，delete将对象析构和内存释放组合在一起。
2. allocator类将内存分配和对象构造分离
**大多数应用都没有直接访问动态数组的需求。当一个应用需要可变数量的对象时，使用标准库容器更简单、安全、高效。**

**在分配动态数组的类则必须定义自己版本的操作，在拷贝、复制、销毁对象时管理所关联的内存**
### new和数组
**没有默认构造函数的类不能使用new动态分配数组**
new分配一个对象数组，返回指向第一个对象的指针。
方法一：
```
//getsize返回一个整数
int *pia = new int[getsize()];
```
方法二：类型别名
```
using arrT = int[42];
int *p=new arrT;//分配一个42个int对象；p指向第一个int
```
##### 分配一个数组会得到一个元素类型的指针
new T[] 分配的内存为“动态数组”，但获得的不是一个数组类型的对象，而是一个**数组元素类型的指针。**
因此不能调用begin等操作
#### 初始化动态分配对象的数组
**示例：**
```
int *pia = new int[10];//10个未初始化的int
int *pia2=new int[10]();//10个值初始化为0的int


/*元素初始化器的花括号列表*/
int *pia3=new int[10]{0,1,2,3,4,5,6,7,8,9};
```
如果初始化器数目小于元素数目，则初始化开始部分元素。否则new表达式失败，抛出`bad_array_new_length`异常

#### 分配一个空数组是合法的
```
char arr[0];//错误：不能定义长度为0的数组
char *cp  = new char[0];//正确，cp像尾后迭代器，不能解引用
```
#### 释放动态数组
动态数组逆序销毁
```
delete p;//p必须指向一个动态分配的对象或为空
delete []pa;//pa必须指向一个动态分配的数组或为空,[]不能省却，否则结果未定义
```
#### 智能指针和动态数组
1. 标准库提供了一个可以管理new分配的数组的unique_ptr版本。
2. shared_ptr不支持直接管理动态数组。需提供自定义删除器

**指向数组的unique_ptr**
指向数组的unqiue_ptr不支持成员访问运算符
其他unique_ptr操作不变
操作 | 含义 
---------|----------
unique_ptr\<T[]\> u | u可以指向一个动态分配的数组，数组元素类型为T 
unique_ptr\<T[]\> u(p) | u指向内置指针p所指向的动态分配的数组。p必须能转换为类型T*
u[i] | 返回u拥有的数组中位置i的对象，u必须指向一个数组

**示例：**
```
unique_ptr<int[]> up(new int[10]);
for(size_t i=0;i!=10;++i){
    up[i]=i;//为每个元素赋予一个新值
}
up.release();//销毁指针和内存
```
**shared_ptr管理动态数组:需自定义删除器**
```
shared_ptr<int> sp(new int[10] , [](int *p){delete[] p;});
sp.reset();
```
shared_ptr未定义下标运算符，而且智能指针类型不支持指针算术运算。因此，为了访问数组中的元素，必须用get获取一个内置指针，然后用它来访问数组元素。
```
for(size_t i=0;i!=10;++i){
    *(sp.get()+i) = i;//使用get获取一个内置指针
}
```
### allocator类
 allocator类将内存分配和对象构造分离，可以在真正需要时才执行对象构建操作，避免不必要的浪费。
#### allocator类
标准库allocator类是一个模板，定义在`memory`中。allocator类根据给定的对象类型来确定恰当的内存大小和对齐位置。

**标准库allocator类及其算法**
操作 | 含义 
---------|----------
allocator\<T\> a| 定义了一个名为a的allocator对象，可以为类型为T的对象分配内存 
 a.allocate(n) |分配一段原始的、未构造的内存，保存n个类型为T的对象。  返回指针
a.deallocate(p,n) | 释放从T*指针p中地址开始的内存，这块内存保存了n个类型为T的对象；p必须是一个先前由allocate返回的指针，且n必须是p创建时所要求的大小，在调用deallocate之前，用户必须对每个在这块内存中创建的对象调用destory
a.construct(p,args)|p必须是一个类型为T*的指针，指向一个原始内存；args被传递给类型为T的构造函数，用来在p指向的内存中构造一个对象
a.destroy(p)|p为T*类型的指针，此算法对p指向的对象执行析构函数
**示例：**
```
allocator<string> alloc;//可以分配string的allocator对象
auto const p = alloc.allocate(n);//分配n个未初始化的string
auto q=p;
alloc.construct(q++);//*q为空字符串
alloc.construct(q++，10,'c');//*q为cccccccccc
alloc.construct(q++,"hi");//*q为hi
```
construct成员函数接受一个指针和零个或多个额外参数，在给定位置构造一个元素。额外参数必须是与构造函数的对象的类型相匹配的合法的初始化器。

**使用未定义的内存，结果是未定义的**
销毁构造的元素
```
while(q!=p)
    alloc.destroy(--q);//释放我们真正构造的string
//释放内存，归还给系统
alloc.deallocate(p,n);
```
**只能对真正构造了的元素进行destroy操作**
#### 拷贝和填充未初始化内存的算法
allocator类定义了两个伴随算法，在头文件`<memory>`中，可以在未初始化内存中创建对象
**allocator算法**
这些函数在给定目的位置创建元素，而不是由系统分配内存给他们。
**返回递增后的指针**
操作|含义|
---------|----------
uninitialized_copy(b,e,b2) | 从迭代器b和e指出输入范围中拷贝元素到迭代器b2指定的未构造的原始内存中。b2指向的内存必须足够大，能容纳输入序列中元素的拷贝 
uninitialized_copy_n(b,n,b2) | 从迭代器b指向的元素开始，拷贝n个元素到b2开始的内存中 
uninitialized_fill(b,e,t) | 在迭代器b和e指定的原始内存范围中创建对象，对象的值均为t的拷贝 
uninitialized_fill_n(b,n,t) | 从迭代器b指向的内存地址开始创建n个对象。b必须指向足够大的未构造的原始内存，能容纳给定数量的对象

