#ifndef BINARYQUERY_H
#define BINARYQUERY_H
#include "Query_base.h"
#include "Query.h"
class BinaryQuery : public Query_base
{
protected:
    Query lhs , rhs;
    string str;
    BinaryQuery(const Query& l , const string& s , const Query& r):lhs(l) , rhs(r) , str(s){}
    string rep()const{ return "("+ lhs.rep() + str+rhs.rep()+")";}

};
#endif