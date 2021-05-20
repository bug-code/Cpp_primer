// #define NDEBUG
#include <vector>
#include "HasPtr.cc"
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::for_each;
int main(){
    string s1("fuck") , s2("you") , s3("mother") , s4("fucker");
    int i1(1),i2(2) , i3(3) , i4(4);
    HasPtr hp1(s1,i1) , hp2(s2,i2) , hp3(s3,i3) , hp4(s4,i4);
    vector<HasPtr> vec{ hp4,hp2 , hp1 , hp3};
    sort(vec.begin() , vec.end());
    for_each(vec.cbegin() , vec.cend() , [](const HasPtr& hp){cout<<hp.getStr()<<" "<<hp.getInt()<<endl;});
    return 0;
}