#include <memory>
#include <string>
#include <iostream>
#include <new>
using namespace std;
int main(){
    string s1("fuck");
    string s2("you");
    auto s1B = s1.cbegin();
    auto s2B = s2.cbegin();
    unique_ptr<char[]> Sup(new char[s1.size()+s2.size()]);
    for (size_t i = 0; i != s1.size(); i++)
    {
        Sup[i] = *s1B;
        ++s1B;
    }
    for (size_t i = s1.size(); i != s1.size()+s2.size(); i++)
    {
        Sup[i] = *s2B;
        ++s2B;
    }
    for (size_t i = 0; i != s1.size()+s2.size(); i++)
    {
        cout<<Sup[i];
    }
    cout<<endl;

    string s3=s1+s2;
    cout<<s3<<endl;
    
    
    return 0 ;
}