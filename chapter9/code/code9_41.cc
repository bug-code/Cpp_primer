#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::endl;
using std::cout;
int main(){
    vector<char> Cvec{'N' , 'M' , 'S' , 'L' };
    string S(Cvec.cbegin() , Cvec.cend());
    cout<<S<<endl;

    return 0;
}