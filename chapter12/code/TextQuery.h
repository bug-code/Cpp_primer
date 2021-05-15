#ifndef TEXTQUERY
#define TEXTQUERY
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

class TextQuery
{
private:
    vector<string> lineVec;
    map<string , set<int>> wordLine;
public:
    TextQuery()=default;
    TextQuery(vector<string> &LV , map<string,set<int>> &WL ):
    lineVec(LV),wordLine(WL){};

    TextQuery(istream &is );
    set<int> getIndex(string &s);
    void print(string &s);
};
TextQuery::TextQuery(istream &is ){
    string line;
    static size_t LineNum=0;
    while (getline(is , line))
    {
        ++LineNum;
        lineVec.push_back(line);
        string word;
        istringstream iss(line);
        while (iss>>word)
        {
            //如果存在，则插入，否则什么也不做
            wordLine[word].insert(LineNum);
        }
    }
}
set<int> TextQuery::getIndex(string &s){
    return wordLine.at(s);
}
void TextQuery::print(string &s){
    auto iter = wordLine.find(s);
    if (iter != wordLine.cend() )
    {
        cout<<s<<" occurs "<< iter->second.size()<<" times "<<endl;
        for (auto beg=iter->second.cbegin() , en =iter->second.cend();beg!=en;++beg)
        {
            cout<<"  (line "<<*beg<<" )"<<lineVec[*beg-1]<<endl;
        }
    }
    else
    {
        cerr<<"No this word in text!"<<endl;
    }
}
#endif