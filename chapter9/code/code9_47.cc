#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

void findNum(const string &finds , const string &instr){
    string::size_type pos = 0;
    while ((pos = instr.find_first_of(finds , pos)) != string::npos )
    {
        cout<<"found number at index: "<<pos
            <<" element is " <<instr[pos]<<endl;
        ++pos;
    }
}
void findChar(const string &finds , const string &inStr){
    string::size_type pos=0;
    while ((pos=inStr.find_first_not_of(finds,pos))!=string::npos)
    {
        cout<<"found char at index: "<<pos
            <<" element is " <<inStr[pos]<<endl;
        ++pos;
    }
}

//test
int main(){
    string s("ab2c3d7R4E6") , numbers("0123456789");
    // findNum(numbers , s);
    findChar(numbers , s);
}