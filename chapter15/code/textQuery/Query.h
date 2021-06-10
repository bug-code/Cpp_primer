#ifndef QUERY_H
#define QUERY_H
#include <memory>
#include "Query_base.h"
#include "myQueryResult.h"
#include "WordQuery.h"
class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query& ,const Query&);
    friend Query operator&(const Query& ,const Query&);
private:
    //构造函数
    Query(const std::shared_ptr<Query_base>& que ):q(que){}
    //指向具体查询操作基类的指针
    std::shared_ptr<Query_base> q;
public:
    Query()=default;
    //构建一个新的WordQuery
    Query(const std::string& s):q(new WordQuery(s)){};
    //调用查询操作，根据动态类型执行查询操作
    myQueryResult eval(const myTextQuery& t)const{return q->eval(t);}
    //查询结果，调用Query_base的rep操作
    string rep()const{return q->rep();}
};
//输出查询结果
ostream& operator<<(ostream& os , const Query& Q){
    return os<<Q.rep();
}
#endif