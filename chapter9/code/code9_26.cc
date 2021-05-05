#include <vector>
#include <list>
#include <iterator>
#include <iostream>
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::end;
using std::begin;

int main(){
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> vec(ia,end(ia) );
    list<int> li(ia,end(ia) );
    auto VecB = vec.begin();
    auto LiB = li.begin();
    for (auto *bia = begin(ia) , *eia=end(ia);  bia!=eia; ++bia)
    {
        if ((*bia)%2)
        {
            LiB=li.erase(LiB);
            ++VecB; 
        }
        else
        {
            VecB=vec.erase(VecB);
            ++LiB;
        }        
    }
    
    for (auto &i : vec)
    {
        cout<< i << " ";
    }
    cout<<endl;
    for (auto &i : li)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}