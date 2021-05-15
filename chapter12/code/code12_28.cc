#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
using namespace std;
void readWords(const string &fileName , shared_ptr<vector<string>> &SVS , map< string,shared_ptr<set<size_t>>> &SM){
    ifstream ifs(fileName);
    if (ifs)
    {
        string line;
        static size_t LineNum=0;
        while (getline(ifs , line))
        {
            SVS->push_back(line);
            ++LineNum;
            string word;
            istringstream iss(line);
            while (iss>>word)
            {
                //如果存在，则插入，否则什么也不做
                auto &lines=SM[word];
                if (!lines)
                {
                    lines.reset(new set<size_t>);
                }
                
                lines->insert(LineNum);
            }
        }
    }
    else
    {
        cerr<<"open file failed"<<endl;
    }  
}
auto search(const string &s ,map< string,shared_ptr<set<size_t>>> &SM)->shared_ptr<set<size_t>>{
    auto st = SM.find(s);
    return   st!=SM.end()? st->second :make_shared<set<size_t>>();
}
void printLine(const string &s , const shared_ptr<vector<string>> &sp , const shared_ptr<set<size_t>> &SS){
    cout<<s <<" occurs "<<SS->size()<<" times "<<endl;
    for (auto beg=SS->cbegin() , en=SS->cend(); beg!=en;++beg)
    {
        cout<<"  (line "<<*beg<<" )"<<(*sp)[*beg-1]<<endl;
    }
}
int main(){
    shared_ptr<vector<string>>  lineVec(new vector<string>);
    map<string,shared_ptr<set<size_t>>>  wordLine;
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter12\\code\\hundredMiles.txt");
    readWords(fileName , lineVec , wordLine);
    while (true )
    {
        string s;
        cout<<"search ? (y/n):"<<endl;
        if (!(cin>>s) || s=="n" ) break;
        auto sptr = search(s , wordLine);
        printLine(s,lineVec , sptr);
    } 
}