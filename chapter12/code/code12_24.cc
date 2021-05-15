#include <iostream>
#include <memory>
#include <string>
#include <new>
using namespace std;
size_t inToSP_arr(istream &is , unique_ptr<char[]> &CUP ){ 
    string str;
    is>>str;
    unique_ptr<char[]> up(new char [str.size()]);
    auto beg = str.cbegin();
    for (size_t i = 0; i != str.size(); i++)
    {
        up[i] = *beg;
        ++beg;
    }
    CUP.reset(up.release());
    return str.size();
}
void printUPArr(const unique_ptr<char[]> &up , const size_t &sz){
    for (size_t i = 0; i !=sz; i++)
    {
        cout<<up[i];
    }
    cout<<endl;
}
int main(){
    unique_ptr<char[]> CUP;
    auto sz=inToSP_arr(cin,CUP);
    printUPArr(CUP , sz);
    return 0;
}