#include <vector>
#include <iostream>
#include <new>
#include <algorithm>
using namespace std;

vector<int>* getVec(){
    return new vector<int>;
}
void saveToVec(istream &is , vector<int>* &ptr){
    if (is)
    {
        int val;
        while (is>>val)
        {
            ptr->push_back(val);
        }
    }
    else
    {
        cerr<<"input stream failed!"<<endl;
    }
}

int main(){
    auto pv = getVec();
    saveToVec(cin,pv);
    for_each(pv->cbegin() , pv->cend() , [](const int &val){ cout<<val<<" ";});
    delete pv;//释放内存
    pv = nullptr;//防止悬空指针
}
