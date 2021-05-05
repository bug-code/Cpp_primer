#include <iostream>
#include <string>
#include <deque>
#include <list>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::string;
using std::istream;
using std::list;
void InStrList(istream &is , list<string> &li){
    string str;
    while (is>>str)
    {
        li.push_back(str);
    }
}
void DeqShow(const list<string> &li){
    auto LiBegin = li.cbegin() , LiEnd = li.cend();
    while (LiBegin!=LiEnd)
    {
        cout<<*LiBegin<<" ";
        ++LiBegin;
    }
    cout<<endl;
}

int main(){
    list<string> Li;
    InStrList(cin , Li);
    DeqShow(Li);
}