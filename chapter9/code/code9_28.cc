#include <forward_list>
#include <iostream>
#include <string>
using std::forward_list;
using std::cout;
using std::endl;
using std::string;
void insertStr(forward_list<string> &FList ,const string &FindStr , const string &insertStr){
    auto prev = FList.cbefore_begin();
    for (auto curr = FList.cbegin() , End=FList.cend(); prev != End ; ++curr,++prev)
    {
        if (curr == End)
        {
            FList.insert_after(prev,insertStr);
            break;        
        }
        if (*curr == FindStr )
        {
            FList.insert_after(curr,insertStr);
            break;
        }
        
    }
}

int main(){
    forward_list<string> FList{"fuck" , "you" , "mother" , "fucker"};
    insertStr(FList , "is" , "asshole");
    for (auto &i : FList)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}