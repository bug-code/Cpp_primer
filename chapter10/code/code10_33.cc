#include <fstream>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string numbers("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\numbers.txt");
    string Even("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\Even.txt");
    string odd("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\odd.txt");
    ifstream ifs(numbers);
    ofstream ofsE(Even , ofstream::app);
    ofstream ofsO(odd , ofstream::app);
    if (ifs && ofsE && ofsO)
    {
        istream_iterator<int> in_int(ifs) , eof_int;
        ostream_iterator<int> out_Even(ofsE,"\n")  , out_Odd(ofsO," ");
        for_each(in_int , eof_int , [&out_Even , &out_Odd](const int &i){ i%2==1 ? out_Odd = i : out_Even =i ; });        
    }
    else
    {
        cout<<"open file failed!"<<endl;
    }
    
    return 0;
}