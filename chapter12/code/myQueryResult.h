#ifndef MYQUERYRESULT_H
#define MYQUERYRESULT_H
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <memory>
#include <iostream>
#include "myTextQuery.h"
// #include "StrBlob.cc"
using namespace std;

class myQueryResult
{
private:
    shared_ptr<vector<string>> spTextLine;
    // StrBlob spTextLine;/*strblob类*/
    shared_ptr< map<string,set<size_t>> > wordLineSet;
    shared_ptr<set<size_t>> LineSet;
    string str;
public:
    myQueryResult(const myTextQuery &mTQ):
                                        spTextLine(mTQ.lineVec),wordLineSet( mTQ.wordLine ){};
    // /*拷贝构造函数*/
    // myQueryResult(const myQueryResult &mTR):spTextLine(mTR.spTextLine) , 
    //                                         wordLineSet(mTR.wordLineSet),LineSet(LineSet),str(mTR.str){}
    // /*赋值运算符*/
    // myQueryResult& operator=(const myQueryResult& mQR){
    //     spTextLine = mQR.spTextLine;
    //     wordLineSet=mQR.wordLineSet;
    //     LineSet=mQR.LineSet;
    //     str=mQR.str;
    // }
    void query(const string &s);
    void print();
    /*练习12.33*/
    set<size_t>::iterator begin(){return LineSet->begin();}
    set<size_t>::iterator end(){return LineSet->end();}
    shared_ptr<vector<string>> getfile(){return spTextLine;}
};
void myQueryResult::query(const string &s){
    str=s;
    static shared_ptr<set<size_t>>  Nodata(new set<size_t>); 
    auto st = wordLineSet->find(s);
    if (st!=wordLineSet->end())
    {
        LineSet=make_shared<decltype((*st).second)>((*st).second);
    }
    else
    {
        LineSet=Nodata;
    }
}
void myQueryResult::print(){
    cout<<str<<" occurs "<<LineSet->size()<<" times "<<endl;
    for (auto beg=begin() , en=end(); beg!=en;++beg)
    {   
        cout<<"  (line "<<*beg<<" )"<<(*spTextLine)[*beg-1]<<endl;
    }
}
#endif