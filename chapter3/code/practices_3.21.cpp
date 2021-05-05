#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    cout<<"容器大小"<<vec.size()<<endl;
     
    for (auto cb = vec.cbegin() , ce = vec.cend() ; cb!=ce ; ++cb)
    {
        cout<<*cb<<" " ;
    }
    
    return 0;
}