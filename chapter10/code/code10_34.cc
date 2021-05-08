#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
int main(){
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    /*练习10.34*/
    // for_each(vec.crbegin() , vec.crend() , [](const int &i){cout<<i<<" ";});
    /*练习10.35*/
    // for(auto beg = vec.cbegin() , en = vec.cend()-1; en>=beg;--en){
    //     cout<<*en<<" ";
    // }
    /*练习10.36*/
    // list<int> ilst{1,2,3,4,5,0,6};
    // auto index_iter = find(ilst.crbegin() , ilst.crend() ,0);
    // cout<<"found value:"<<*index_iter;
    /*练习10.37*/
    list<int> lst(4);
    copy(vec.crbegin()+3 , vec.crbegin()+7 , lst.begin());
    
    // auto it = front_inserter(lst);
    // copy(vec.cbegin()+3 , vec.cbegin()+7 , it);
    
    for_each(lst.cbegin() , lst.cend() , [](const int &i){cout<<i<<" ";});

}