#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(){
    vector<int> vec;
    int val;
    while (cin>>val)
    {
        vec.push_back(val);
    }

    for (size_t i = 0 ; i < vec.size(); i++)
    {
        int j = i+1;
        if (j<vec.size())
        {
            cout<< vec[i]+vec[j]<<" " ;
        }

    }

    for (size_t i = 0 , j = vec.size()-1; i <=j; i++ , j--)
    {
        cout<<vec[i]+vec[j]<<" " ;
    }
    
    
    
}