#include <list>
#include <vector>
#include <iostream>
#include <string>
using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::string;
void show(vector<double> &vec){
    for (auto &i : vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    /*练习9.13*/
    list<int> ListInt{0,1,2,3,4,5,6,7,8,9};
    vector<int> VecInt{0,1,2,3,4,5,6,7,8,9};
    vector<double> VecDouble1(ListInt.cbegin() , ListInt.cend());
    vector<double> VecDouble2(VecInt.cbegin() ,VecInt.cend());
    show(VecDouble1);
    show(VecDouble2);
    /*练习9.14*/
    // list<char *> ListPtr;
    // vector<string> VecStr;
    // VecStr.assign(ListPtr.cbegin() , ListPtr.cend());
    return 0;
}