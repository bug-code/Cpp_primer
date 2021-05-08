#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
#include <iostream>
using std::count;
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::string;
using std::accumulate;
int main(){
    vector<int> vecInt{1,2,3,4,2,4,3,1,5,33};
    auto begin_vecInt = vecInt.cbegin() , end_vecInt=vecInt.cend();
    /*练习10.1*/
    cout<<count(begin_vecInt , end_vecInt , 2)<<endl;
    /*练习10.3*/
    cout<<accumulate(begin_vecInt , end_vecInt , 0)<<endl;
    /*练习10.2*/
    list<string> vecStr{"N" , "M" , "s" , "L" , "yes" ,"yes"};
    auto begin_vecStr = vecStr.cbegin() , end_vecStr=vecStr.cend();
    cout<<count(begin_vecStr , end_vecStr , "yes")<<endl;
    /*练习10.4*/
    vector<double> vecD{1.2,3.2,5.6};
    auto begin_vecD = vecD.cbegin() , end_vecD=vecD.cend();
    cout<<accumulate(begin_vecD  , end_vecD , 0)<<endl;
    return 0;
}