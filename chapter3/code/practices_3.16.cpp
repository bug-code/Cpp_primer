#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main(){
    // vector<int> v1;
    // cout<<"容器大小"<<v1.size()<<endl;
    // for ( auto &vali:v1)
    // {
    //     cout<<vali<<" ";
    // }
    
    // vector<int> v2(10);
    // cout<<"容器大小"<<v2.size()<<endl;
    // for ( auto &vali:v2)
    // {
    //     cout<<vali<<" ";
    // }

    // vector<int> v3(10,42);
    // cout<<"容器大小"<<v3.size()<<endl;
    // for ( auto &vali:v3)
    // {
    //     cout<<vali<<" ";
    // }

    // vector<int> v4{10};
    // cout<<"容器大小"<<v4.size()<<endl;
    // for ( auto &vali:v4)
    // {
    //     cout<<vali<<" ";
    // }

    // vector<int> v5{10,42};
    // cout<<"容器大小"<<v5.size()<<endl;
    // for ( auto &vali:v5)
    // {
    //     cout<<vali<<" ";
    // }

    // vector<string> v6{10};
    // cout<<"容器大小"<<v6.size()<<endl;
    // for ( auto &vali:v6)
    // {
    //     cout<<vali<<" ";
    // }
    // return 0;

    vector<string> v7{10,"hi"};
    cout<<"容器大小"<<v7.size()<<endl;
    for ( auto &vali:v7)
    {
        cout<<vali<<" ";
    }
}