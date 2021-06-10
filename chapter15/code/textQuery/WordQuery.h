#ifndef WORDQUERY_H
#define WORDQUERY_H
#include "Query_base.h"
#include "Query.h"
class WordQuery :public Query_base
{
    friend class Query;
private:
    //覆盖重载 基类eval函数
    myQueryResult eval(const myTextQuery& )const;
    string rep()const{return queryWord;}
    string queryWord;
    WordQuery()=default;
    WordQuery(const string& s):queryWord(s){};
    WordQuery(string&& s):queryWord(std::move(s)){}
};
myQueryResult WordQuery::eval(const myTextQuery& q)const{
    myQueryResult mTQ(q , nullptr , queryWord);
    mTQ.query(queryWord);
    return mTQ;
}

#endif