#ifndef ANDQUERY_H
#define ANDQUERY_H
#include "BinaryQuery.h"
#include <algorithm>
class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
private:
    AndQuery()=default;
    AndQuery(const Query& l , const Query& r):BinaryQuery(l,"&",r){}
    myQueryResult eval(const myTextQuery&)const;
};
inline Query operator&(const Query& lhs , const Query& rhs){
    return std::make_shared<Query_base>(new AndQuery(lhs , rhs));
}
myQueryResult AndQuery::eval(const myTextQuery& mTQ)const{
    auto l = lhs.eval(mTQ) , r=rhs.eval(mTQ);
    auto ret_lines = make_shared<set<size_t>>();
    std::set_intersection(l.begin() , l.end(),
                        r.begin() , r.end(),
                        std::inserter(*ret_lines , ret_lines->begin()));
    return myQueryResult(mTQ , ret_lines , rep());
}
#endif