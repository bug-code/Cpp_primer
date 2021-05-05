#include <iostream>
#include <string>
#include <deque>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::string;
using std::istream;

void InStrDeque(istream &is , deque<string> &deq){
    string str;
    while (is>>str)
    {
        deq.push_back(str);
    }
}
void DeqShow(const deque<string> &deq){
    auto DeqBegin = deq.cbegin() , DeqEnd = deq.cend();
    while (DeqBegin!=DeqEnd)
    {
        cout<<*DeqBegin<<" ";
        ++DeqBegin;
    }
    cout<<endl;
}

int main(){
    deque<string> deq;
    InStrDeque(cin , deq);
    DeqShow(deq);
}