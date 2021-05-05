#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

//定义简单的电话簿类(聚合类)
struct personInfo
{
    string name;
    vector<string> phones;
};

//从文件读取电话数据
void ReadPhonesToVec(const string &phoneFile , vector<personInfo> &phoneVec ){
    ifstream istrm(phoneFile , ifstream::in);
    if (istrm)
    {   string str;
        while (std::getline(istrm ,str))
        {
            personInfo info;
            istringstream isstrm(str);
            isstrm>>info.name;
            string phone;
            while (isstrm>>phone)
            {
                info.phones.push_back(phone);
            }
            phoneVec.push_back(info);
        }
    }
}

void PrintPhoneInfo(const vector<personInfo> &phonevec){
    for (const auto &i : phonevec)
    {
        std::cout<<i.name<<" ";
        for (const auto &phone : i.phones)
        {
            std::cout<<phone<<" ";            
        }
        std::cout<<std::endl;
    }
}

int main(int argc , char *argv[]){
    vector<personInfo> phoneVec;
    ReadPhonesToVec(argv[1] , phoneVec);
    PrintPhoneInfo(phoneVec);
    return 0;
}
