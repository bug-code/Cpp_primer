#include <fstream>
#include <iostream>
#include "StrBlob.cc"
#include "StrBlobPtr.cc"
using namespace std;
void inStrBlob(StrBlob& sb ,const string &fileName){
    ifstream ifs(fileName);
    if (ifs)
    {
        string str;
        while (ifs>>str)
        {
            sb.push_back(str);
        }
    }
    else
    {
        cerr<<"open file failed"<<endl;
    }
    
}

int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter12\\code\\words.txt");
    StrBlob sb;
    inStrBlob(sb,fileName);
    // 没有重载StrBlobPtr的操作符
    // for_each(sb.begin() , sb.end() , [](const string &s){cout<<s<<" ";});
    for (auto beg = sb.cbegin() , en = sb.cend(); beg!=en;++beg)
    {
        cout<<*beg<<" ";
    }
    cout<<endl;
    return 0;
}
