#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using std::istream;
using std::string;
using std::ifstream;

string  findSquareStr(const string &fileStr , const string &squareStr){
    string maxLenSquareStr;
    string::size_type pos= 0;
    while ((pos=fileStr.find_first_of(squareStr , pos))!=string::npos )
    {
        int len =0;
        for (string::size_type end_pos = pos; squareStr.find(fileStr[end_pos]) != string::npos; ++end_pos)
        {
            ++len;
        }
        string tmpMaxLenStr(fileStr , pos , len);
        if (tmpMaxLenStr.size() > maxLenSquareStr.size())
        {
            maxLenSquareStr=tmpMaxLenStr;
        }
        
        pos += len;
    }
    return maxLenSquareStr;
}

string getfileStr(istream &is){
    std::stringstream buffer;
    buffer << is.rdbuf();
    string contents(buffer.str());
    return contents;
}

int main(){
    string squareStr("acemnorsuvwxz");
    string fileName = "F:\\code\\C++_code\\C++ note\\Cpp_primer\\ch9\\code\\test.txt";
    ifstream ifs(fileName);
    string fileStr;
    if (ifs)
    {
        fileStr = getfileStr(ifs);
    }
    string maxLenSquarestr = findSquareStr(fileStr , squareStr);
    std::cout<<maxLenSquarestr<<std::endl;
    return 0;
}