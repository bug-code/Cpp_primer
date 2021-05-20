#include <iostream>
#include <vector>
#include <new>
using std::cout;
using std::endl;
using std::vector;
class X
{
private:
    /* data */
public:
    X(){cout<<"默认构造函数"<<endl;}
    X(const X& x){cout<<"拷贝构造函数"<<endl;}
    X& operator=(const X &x){cout<<"拷贝赋值运算符"<<endl;}
    ~X(){cout<<"析构函数"<<endl;}
};
//非引用传递
void f1(X x){}
//引用传递
void f2(const X &x){}

int main(){
    X a , c;
    a=c;
    f1(a);
    f2(a);
    X *b = new X;
    vector<X> vecx;
    vecx.push_back(*b);
    delete b;
    return 0;
}