#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::cout;
using std::endl;
double getSum(const vector<string> &vec){
    double sum=0;
    for (auto &i : vec)
    {
        sum+=std::stof(i);
    }
    return sum;
}
int main(){
    vector<string> vec;
    for (size_t i = 0; i < 10; i++)
    {
        vec.push_back(std::to_string(i));
    }
    double sum= getSum(vec);
    cout<<sum<<endl;
    
    return 0;
}