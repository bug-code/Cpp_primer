#ifndef NOTQUERY_H
#define NOTQUERY_H
#include "Query_base.h"
#include "Query.h"
class NotQuery:public Query_base
{
    friend Query operator~(const Query&);
private:
    Query que;
    NotQuery()=default;
    NotQuery(const Query &q):que(q){}
    string rep()const{ return "~("+que.rep()+")";}
    //覆盖重载 基类 函数
    myQueryResult eval(const myTextQuery&)const;

};
inline Query operator~(const Query& q){
    return std::make_shared<Query_base>(new NotQuery(q));
}
inline myQueryResult NotQuery::eval(const myTextQuery& mTQ)const{
    auto result = que.eval(mTQ);
    auto ret_lines = make_shared<set<size_t>>();
    auto beg = result.begin() , en = result.end();
    auto sz = mTQ.text_Line_size();
    for (size_t i = 1; i !=sz; i++)
    {
        if (beg==en||*beg!=i)
        {
            ret_lines->insert(i);
        }
        else if (beg!=en)
        {
            ++beg;
        }
    }
    return myQueryResult(mTQ , ret_lines , rep());
}
#endif