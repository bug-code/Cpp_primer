#include <vector>
#include <list>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::list;
int main(){
    vector<int> vec1{0,1,2,3,4};
    list<int> List{6,5,2,7,3};
    vector<int> vec2{0,1,2,3,4,5};
    cout<<(vec1==vec2 ? "ture":"false")<<endl;
    /*练习9.16*/
    cout<< (vector<int>(List.cbegin() , List.cend())==vec1 ? "true":"false")<<endl;
}