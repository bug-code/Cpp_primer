#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include "myQueryResult.h"
class Query_base
{
    friend class Query;
private:
    /*返回与当前Query匹配的QueryResult*/
    virtual myQueryResult eval(const myTextQuery&) const=0;//实际执行&|!查询的操作
    // /*用于展示工作流程的函数（可有可无）*/
    virtual string rep()const=0;
protected:
    // virtual ~Query_base()=default;
};
#endif