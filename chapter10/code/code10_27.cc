#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main(){
    /*练习10.27*/
    vector<int> vecSource{0,1,2,3,1,2,4,6,3,2,8,5};
    sort(vecSource.begin() , vecSource.end());
    vector<int> vecdes;
    auto it = back_inserter(vecdes);
    /*unique_copy函数中的序列需要实现排好序*/
    unique_copy(vecSource.cbegin() , vecSource.cend() , it);
    for_each(vecdes.cbegin() , vecdes.cend() , [](const int &i){cout<<i<<" ";});
    cout<<endl;
    /*练习10.28*/
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    vector<int> vec1;
    vector<int> vec2;
    deque<int> deq3;
    

    copy(vec.cbegin() , vec.cend() , inserter(vec1 , vec1.begin()));
    for_each(vec1.cbegin() , vec1.cend() , [](const int &i){cout<<i<<" ";});
    cout<<endl;
    copy(vec.cbegin() , vec.cend() , back_inserter(vec2));
    for_each(vec2.cbegin() , vec2.cend() , [](const int &i){cout<<i<<" ";});
    cout<<endl;
    copy(vec.cbegin() , vec.cend() , front_inserter(deq3));
    for_each(deq3.cbegin() , deq3.cend() , [](const int &i){cout<<i<<" ";});

}