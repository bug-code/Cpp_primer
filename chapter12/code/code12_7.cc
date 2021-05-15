#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;

shared_ptr<vector<int>> getVec(){
    return make_shared<vector<int>>();
}
void saveToVec(istream &is , shared_ptr<vector<int>> &ptr){
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
}
