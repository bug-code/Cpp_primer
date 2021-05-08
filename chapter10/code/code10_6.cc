#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>
using std::list;
using std::begin;
using std::end;
using std::cout;
using std::endl;
using std::fill_n;
int main(){
    list<int> ilst{0,1,2,3,4,5};
    fill_n(begin(ilst) , ilst.size() , 0);
    for (auto &i : ilst)
    {
        cout<<i<<endl;
    }
    
    return 0;
}