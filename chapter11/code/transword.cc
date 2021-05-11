#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
/*单词转换*/
const string strToStr (unordered_map<string,string> &transFile  , const string str ){
    if (transFile.find(str) != transFile.cend())
    {
        return transFile[str];
    }
    else
    {
        return str;
    }
}
/*构建单词转换map*/
auto getTransMap(istream &is){
    string line;
    //无序容器类型，无序容器可以无缝替换有序容器
    unordered_map<string,string> mp;
    while (getline(is,line))
    {
        auto pos = line.find(' ');
        string key(line,0 , pos);
        string value(line , pos+1 ,line.size()-pos-1 );
        mp.insert({key,value});
    }
    return mp;
}

/*文件转化*/
void toTransFile(istream  &regularFile , istream &sourceFile , const string &destFile){
    auto transMap = getTransMap(regularFile);
    string sourceLine;
    ofstream oss(destFile,ofstream::app);
    if (oss)
    {
        while (getline(sourceFile , sourceLine))
        {
            string destLine;
            string sourceWord;
            istringstream iss(sourceLine);
            while (iss>>sourceWord)
            {
                auto destWord=strToStr(transMap , sourceWord);
                destLine +=destWord+" ";
            }
            oss<<destLine<<endl;   
        }
    }
    else
    {
        cerr<<"open file failed, you mother fucker"<<endl;
    }
}

int main(){
    string regularFile("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter11\\code\\regularFile.txt");
    string sourceFile("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter11\\code\\sourceFile.txt");
    string destFile("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter11\\code\\destFile.txt");
    ifstream isRegularFile(regularFile);
    ifstream isSourceFile(sourceFile);
    if (isRegularFile && isSourceFile)
    {
        toTransFile(isRegularFile , isSourceFile , destFile);
    }
    else
    {
        cerr<<"open file failed, you mother fucker"<<endl;
    }    
    return 0;
}