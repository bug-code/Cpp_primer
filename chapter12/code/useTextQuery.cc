#include "TextQuery.h"
#include <fstream>

int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter12\\code\\hundredMiles.txt");
    ifstream ifs(fileName);
    TextQuery TQ(ifs);
    string s("miles");
    TQ.print(s);
    return 0;
}


