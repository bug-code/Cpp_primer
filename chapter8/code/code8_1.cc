#include <iostream>
#include <string>
#include <sstream>
using std::ostream;
using std::cin;
using std::cout;
using std::istream;
using std::string;
using std::istringstream;
istream &myPrint(istream &is){
    string s;
    while (is>>s)
    {
        cout << s<<std::endl;
    }
    is.clear();
    return is;    
}

int main(){
    istringstream istrm("NMSL");
    myPrint(istrm);
    cout<<cin.rdstate()<<std::endl;
    return 0;
}
