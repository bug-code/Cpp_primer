#include <deque>
#include <list>
#include <iostream>
using std::deque;
using std::list;
using std::cout;
using std::endl;
void DeqShow(const deque<int> &deq){
    auto DeqBegin = deq.cbegin() , DeqEnd = deq.cend();
    while (DeqBegin!=DeqEnd)
    {
        cout<<*DeqBegin<<" ";
        ++DeqBegin;
    }
    cout<<endl;
}
void differEvenOdd(const list<int> &li , deque<int> &EvenDeq , deque<int> &OddDeq ){
    auto LiBegin = li.cbegin() , LiEnd= li.cend();
    while (LiBegin != LiEnd)
    {
        (*LiBegin%2==0) ? EvenDeq.push_back(*LiBegin) : OddDeq.push_back(*LiBegin);
        ++LiBegin;
    }
}


int main(){
    list<int> li{0,1,0,5,4,84,6,465,6,4,464,7};
    deque<int> EvenDeq , OddDeq;
    differEvenOdd(li , EvenDeq , OddDeq);
    DeqShow(EvenDeq);
    DeqShow(OddDeq);
    return 0;
}
