#ifndef ORQUERY_H
#define ORQUERY_H
#include "BinaryQuery.h"
#include "Query.h"
class OrQuery : public BinaryQuery
{
private:
    friend Query operator|(const Query&  , const Query&);
    OrQuery()=default;
    OrQuery(const Query& lhs , const Query& rhs):BinaryQuery(lhs , "|" , rhs) {}
    string rep()const{return "("+ lhs.rep()+"|"+rhs.rep()+")";}
    myQueryResult eval(const myTextQuery&) const;

};
Query operator|(const Query& lhs , const Query& rhs){
    return std::make_shared<Query_base>(new OrQuery(lhs , rhs));
}
myQueryResult OrQuery::eval(const myTextQuery& mTQ)const{
    auto r=rhs.eval(mTQ) , l=lhs.eval(mTQ);
    auto ret_lines = make_shared<set<size_t>>(r.begin() , r.end());
    ret_lines->insert(l.begin() , l.end());
    return myQueryResult(mTQ , ret_lines , rep());
}
#endif