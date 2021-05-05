#include <stack>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::stack;


/*运算符函数*/
double baseCount(const char left , const char countSymbol , const char right){
    // cout<<left<<endl;
    string le(1,left) , ri(1,right);
    double  l=std::stoi(le) , r=std::stoi(ri);
    // char sym = countSymbol[0];
    int result;
    switch (countSymbol)
    {
    case '*':
        result = l*r;
        break;
    case '/':
        if (r <= 0)
        {
            std::cerr<<"The divisor cannot be 0 "<<endl;
            break;
        }
        else
        {
            result = l/r;
            break;
        }
    case '+':
        result = l+r;
        break;
    case '-':
        result =l-r;
        break;
    default:
        break;
    }
    return result;
}


/*运算括号内结果函数*/
void countResult(stack<char> &stk){
    //需计算的括号内的内容
    stack<char> countStr;
    while ((stk.top()) != '(')
    {
        char s = stk.top();
        countStr.push(s);
        stk.pop();
    }
    

    string s;
    while(!countStr.empty())
    {
        auto c = countStr.top();
        s+=c;
        countStr.pop();
    }
    //计算s结果
    //先算乘除
    while (s.find('*') !=string::npos || s.find('/')!=string::npos )
    {
        auto timesPos = s.find('*') , dividePos = s.find('/');
        auto minPos = std::min(timesPos , dividePos);
        int tmps =baseCount(s[minPos-1] ,s[minPos] ,s[minPos+1] );
        s.replace(minPos-1,3,std::to_string(tmps));
        
    }
    //计算加减
    while (s.find('+') !=string::npos || s.find('-')!=string::npos)
    {
        auto timesPos = s.find('+') , dividePos = s.find('-');
        auto minPos = std::min(timesPos , dividePos);
        int tmps =baseCount(s[minPos-1], s[minPos] ,s[minPos+1]);
        s.replace(minPos-1,3,std::to_string(tmps));
    }
    //pop左括号
    stk.pop();
    //push计算结果
    stk.push(s[0]);
}
//表达式初始化和计算
/*栈初始化函数*/
void initStack(stack<char> &stk , const string &s){
    for (auto &cha : s)
    {  
        if (cha!=')')
        {
            stk.push(cha);
        }
        else
        {
            countResult(stk);
        }
    }
}
void printStack(stack<char> stk){
    stack<char> tmpStk;
    while (!stk.empty())
    {
        auto s = stk.top();
        tmpStk.push(s);
        stk.pop();
    }
    while (!tmpStk.empty())
    {
        cout<<tmpStk.top();
        tmpStk.pop();
    }
    cout<<endl;
}

int main(){
    stack<char> stk;
    string s("NMSL ((3+6/2*1)-(4/2+2))");
    initStack(stk , s);
    printStack(stk);
    return 0;
}