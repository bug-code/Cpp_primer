#ifndef MYTEXTQUERY_H
#define MYTEXTQUERY_H
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <utility>
#include <memory>
#include <new>
// #include "StrBlob.cc"
using std::map;
using std::set;
using std::vector;
using std::string;
using std::istream;
using std::istringstream;
using std::make_pair;
using std::pair;
using std::make_shared;
using std::shared_ptr;
class myQueryResult;
class myTextQuery
{
private:
    shared_ptr<vector<string>>  lineVec;
    // StrBlob lineVec;///*strblob类*/
    shared_ptr<map<string,set<size_t>>>  wordLine;
public:
    friend class myQueryResult;
    myTextQuery(istream &is);
    size_t text_Line_size()const{return lineVec->size();}

};
myTextQuery::myTextQuery(istream &is):
lineVec(new vector<string>),
wordLine(new map<string,set<size_t>>)
{
    string line;
    static size_t LineNum=0;
    while (getline(is , line))
    {
        lineVec->push_back(line);

        // lineVec.push_back(line);///*strblob类*/
        ++LineNum;
        string word;
        istringstream iss(line);
        while (iss>>word)
        {
            (*wordLine)[word].insert(LineNum);
        }
    }
}
#endif