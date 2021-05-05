#include <list>
#include <deque>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::list;
using std::deque;
using std::vector;
//练习9.2
// list<deque<int>> listDeInt;

//练习9.4
bool hasValue(vector<int>::const_iterator &begin , vector<int>::const_iterator &end, const int &val){
    bool flag=false;
    while (begin!=end)
    {
        if (*begin==val)
        {
            flag=true;
            break;
        }
        ++begin;
    }
    return flag;
}

//练习9.5
vector<int>::const_iterator FindValue(vector<int>::const_iterator &begin , vector<int>::const_iterator &end, const int &val){
    while (begin!=end)
    {
        if (*begin==val)
        {
            return begin;
            break;
        }      
        ++begin;  
    }
    return end;
}

//test
int main(){
    vector<int> vecInt{0,1,2,3,4,5,6,7,8,9};
    using citer=vector<int>::const_iterator;
    citer begin=vecInt.cbegin();
    citer end=vecInt.cend();
    int findval=10;
    citer Rciter=FindValue( begin, end,findval);
    cout<< *Rciter<<endl;    
    return 0;
}

