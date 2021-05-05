# IO库
## IO类

头文件 | 类型
---------|----------
 iostream |istream , wistream从流读取数据  
 - | ostream , wostream 向流写入数据 
 - | iostream , wiostream读写流
 fstream | ifstream , wifstream从文件读取数据
 - | ofstream , wofstream向文件写入数据
 - |fstream , wfstream读写文件
 sstream | istringstream , wistringstream从string读取数据
 - | ostringstream , wostringstream向string写入数据 
 - | stringstream ,wstringstream读写string 

### IO对象无拷贝或赋值
进行IO操作的函数通常以引用方式传递和返回流。读写一个IO对象会改变其状态，因此传递和返回引用不能是const.

### 条件状态
IO操作时可能发生错误的。


**IO库条件状态**
函数 | 标志 
---------|----------
 strm::iostate | strm时一种IO类型。iostate是一种机器无关的类型，提供了表达条件状态的完整功能 
 strm::badbit | strm::badbit用来指出流已崩溃 
 strm::failbit | strm::failbit用来指出一个IO操作失败了
 strm::eofbit|用来指出流到达了文件结束
 strm::goodbit|用来指出流未处于错误状态，此值保证为0
 s.eof()|若流s的eofbit置位，则返回true
 s.fail()|若流s的failbit或badbit置位，则返回true
 s.bad()|若流s的badbit置位，则返回ture
 s.good()|若流s处于有效状态，则返回true
 s.clear()|将流s中所有条件状态复位，将流的状态设置为有效，返回void
 s.clear(flags)|根据给定的flags标志位，将流s中对应条件状态位复位。flags的类型为strm::iostate。返回void
 s.setstate(flags)| 根据给定的flags标志位，将流s中对应条件状态位置位。flags的类型位strm::iostate。返回void
 s.rdstate()|返回流s的当前条件状态。返回值类型位strm::iostate

- badbi表示系统级错误
- failbit表示可恢复错误
- 若大袋文件结束位置，则eofbit和failbit都会被置位
- goodbit为0，表示未发生错误

 因此代码通常应该在使用一个流之前检查它是否处于良好的状态。确定一个流对象的状态的最简单的方法是将它作为一个条件来使用。

### 管理条件状态
示例：
```
//复位failbit和badbit,保持其他标志位不变
cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
```
### 管理输出缓冲区
每个输出流都管理一个缓冲区，用来保存程序读写的数据。
有了缓冲机制，操作系统可以将程序的多个输出操作组合成单一的系统级写操作。

**导致缓冲刷新的原因：**
1. 程序正常结束，作为main函数的return操作的一部分，缓冲区刷新被执行
2. 缓冲区满时，需要刷新缓冲，而后新的数据才能继续写入缓冲区
3. 可以使用endl操作符来显式的刷新缓冲区
4. 在每个输出操作之后，可以用操作符unitbuf设置流的内部状态，来清空缓冲区。默认情况下，对cerr是设置unitbuf的，因此写到cerr的内容都是立即刷新的
5. 一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流时，关联到的流的缓冲区会被刷新。例如，默认情况下，cin和cerr都关联到cout。因此，读cin或写cerr都会导致cout的缓冲区被刷新。

刷新输出缓冲区示例：
```
cout<<"hi!"<<endl;//输出然后换行，最后刷新缓冲区
cout<<"hi!"<<flush; //输出hi，然后属性缓冲区，不附加任何额外字符
cout<<"hi!"<<ends;//输出hi和一个空字符，然后刷新缓冲区
```
**unitbuf操作符**
```
//所有输出操作后都会立即刷新缓冲区
cout<<unitbuf;//任何输出都立即刷新，无缓冲
cout<<nounitbuf; //回到正常的缓冲方式
```
*如果程序崩溃，则输出缓冲区不会被刷新*

**关联输入和输出流**
当一个输入流被关联到一个输出流时，任何试图从输入流读取数据的操作都会先刷新关联的输出流。

*交互式系统通常应该灌篮输入流和输出流。这意味着所有输出，包括用户提示信息，都会在读操作之前被打印出来。*

`tie`有两个重载的版本。
1. 不带参数，返回指向输出流的指针。如果本对象当前关联到一个输出流，则返回的就是指向这个流的指针。如果未关联到输出流，则返回空指针。
2. 接受一个指向ostream的指针，将自己关联到此ostream,即x.tie(&o)将流x关联到输出流o。
3. 每个流同时最多关联到一个流，但多个流可以同时关联到同一个ostream。

### 文件输入输出
ifstream、ofstream、fstream这些类型提供的操作与我们之气那已经使用过的对象cin和cout操作一样。

**fstream特有操作**

函数 | 含义 
---------|----------
fstream fstrm;| 创建一个未绑定的文件流，fstream是头文件fstream中定义的一个类型 
fstream fstrm(s);| 创建一个fstream,并打开名未s的文件。s可以是string类型，或者是一个指向C风格字符串的指针。这些构造函数都是explicit的。默认的文件模式mode依赖于fstream的类型 
fstream fstrm(s , mode) | 与前一个构造函数类似，但按指定mode打开文件
fstrm.open(s) |打开名为s的文件，并将文件与fstrm绑定。s可以是一个string或一个指向C风格字符串的指针。默认的文件mode依赖于fstream的类型。返回void
fstrm.close()|关闭与fstrm绑定的文件，返回void
fstrm.is_open()|返回一个bool值，指出与fstrm关联的文件是否成功打开且尚未关闭
#### 使用文件流对象
每个文件流类都定义了一个名为open的成员函数，它完成一些系统相关的操作，来定位给定的文件，并视情况打开为读或写模式。
创建文件流对象时，可以提供文件名(可选)，如果提供以恶搞文件名，则open会自动被调用。
```
ifstream in(ifile); //构造一个ifstream并打开给定文件
ofstream out; //输出文件流并未关联到任何文件
``` 
定义了一个输入流in，它被初始化为从文件读取数据，文件名由string类型的参数ifile指定。

**用fstream代替iostream&**
在要求使用基类型对象的地方，我们可以用其子类对象来代替。

**成员函数open和close**
一旦一个文件流已经打开，它就保持与对应文件的关联。
为了将文件流关联到另外一个文件，必须首先关闭已经关联的文件。一旦文件成功关闭，我们可以打开新的文件。
**自动构造和析构**
当fstream对象被销毁时，close会自动被调用
### 文件模式
每个流都有一个关联的**文件模式**，用来指出如何使用文件。

文件模式 | 含义 
---------|----------
 in | 以读方式打开 
 out | 以写方式打开 
 app | 每次写操作前均定位到文件末尾
ate | 打开文件后立即定位到文件末尾
trunc| 截断文件
binary | 以二进制方式进行IO

**指定文件模式有以下限制：**
1. 只可以对ofstream或fstream对象设定out模式
2. 只可以对ifstream或fstream对象设定in模式
3. 只有当out也被设定时才可以设定trunc模式
4. 只要trunc没被设定，就可以设定app模式。在app模式下，即使没有显示指定out模式，文件也总是以写方式被打开
5. 默认情况下，即使没有指定trunc，以out模式打开的文件也会被截断。为了保留以out模式打开的文件内容，我们必须同时指定app模式。这样智慧将数据追加写到文件末尾，或者同时指定in模式，即打开文件同时进行读写操作
6. ate和binary模式可用于任何类型的文件流对象，且可以与其他任何文件模式组合使用。

**以out模式打开文件会丢弃已有数据**
*保留被ofstream打开的文件中已有数据的唯一方法是显示指定app或in模式*
**每次调用open时都要确定文件模式**
*在每次打开文件时，都要设置文件模式，可能显示设置，也可能隐式设置。当程序未指定时，就使用默认值*

### string流
**sstream**头文件定义了三个类型来支持内存OI，这些类型可以向strig写入数据，从string读取数据。

- istringstream从string读取数据
- ostringstream向string写入数据
- stringstream即可以读取数据也可以写入数据
- sstream中定义的类型都继承自iostream头文件中定义的类型

操作 | 含义 
---------|----------
sstream strm | strm是一个未绑定的stringstream对象。sstream是头文件sstream中定义的一个类型 
sstream strm(s) | strm是一个sstream对象，保存string s的一个拷贝，此构造函数是explicit的 
strm.str() | 返回strm所保存的string的拷贝
strm.str(s)| 将string s 拷贝到strm中，返回void

#### istringstream
当某些工作是对整行文本进行处理，而其他一些工作是处理行内的单个单词时，可以使用istringstream。

#### ostringstream
当我们逐步构造输出，希望最后一起打印时，ostringstream是很有用的。可以先将输出内容写入到一个内存ostringstream中。
