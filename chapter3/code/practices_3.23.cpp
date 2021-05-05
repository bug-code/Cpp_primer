#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,10};
    for (auto b=vec.begin(),e=vec.end(); b!=e; ++b)
    {
        *b=(*b)*2;
    }
    
    for (auto b=vec.begin(),e=vec.end(); b!=e; ++b)
    {
        cout<<*b<<" ";
    }
    
}