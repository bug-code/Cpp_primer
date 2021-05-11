#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
void readPair(istream &is , vector<pair<string,int>> &vec){
    string str;
    while (is>>str)
    {
        int i;
        is>>i;
        /*方式一*/
        vec.push_back(make_pair(str,i));
        /*方式二*/
        vec.push_back(pair<string,int>(str,i));
        /*方式三*/
        vec.push_back({str,i}); 
    }
}

int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter11\\code\\str_int.txt");
    ifstream ifs(fileName);
    if (ifs)
    {
        vector<pair<string,int>> Pvec;
        readPair(ifs,Pvec);
        for_each(Pvec.cbegin() , Pvec.cend() , [](const pair<string,int> &p){ cout<<p.first<<" "<<p.second<<endl; });
    }
    else
    {
        cerr<<"open file failed, mother fucker"<<endl;
    }
    
}