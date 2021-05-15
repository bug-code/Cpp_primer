#include "myQueryResult.h"
#include "myTextQuery.h"
#include <fstream>

int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter12\\code\\hundredMiles.txt");
    ifstream ifs(fileName);
    myTextQuery TQ(ifs);
    while (true)
    {
        cout<<"enter word to search or enter q to quite:";
        string s;
        if(!(cin>>s) || s=="q")break;
        myQueryResult mQR(TQ);
        mQR.query(s);
        mQR.print();
    }
    return 0;
}
