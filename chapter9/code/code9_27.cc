#include <forward_list>
#include <iostream>
using std::forward_list;
using std::cout;
using std::endl;

void delEven(forward_list<int> &FLi){
    auto prev = FLi.before_begin();
    auto Eiter= FLi.cend() , curr = FLi.cbegin();
    while (curr!=Eiter)
    {
        if ((*curr)%2)
        {
            curr=FLi.erase_after(prev);
        }else
        {
            ++prev;
            ++curr;            
        }
    }    
}
int main(){
    forward_list<int> fli{0,1,1,2,3,5,8,13,21,55,89};
    delEven(fli);
    for (auto &i : fli)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}