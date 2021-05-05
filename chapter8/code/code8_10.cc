#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using std::vector;
using std::string;
using std::istringstream;
using std::ifstream;
void ReadFileToVec(const string &FileName , vector<string> &vec){
    ifstream ifstrm(FileName , ifstream::in);
    if (ifstrm)
    {
        string strLine;
        while (std::getline(ifstrm , strLine))
        {
            vec.push_back(strLine);
        }
    }
}

void IstrFromVec(vector<string> &vec){
    for (const auto &i : vec)
    {
        istringstream isstrm(i);
        string word;
        while (isstrm>>word)
        {
            std::cout<<word<<std::endl;
        }
    }
}

int main(int argc , char *argv[]){
    vector<string> vecLine;
    ReadFileToVec(argv[1] , vecLine);
    IstrFromVec(vecLine);
    return 0;
}