#include "date.h"
date::date( const string &s){
    string numbers("0123456789");
    //判断日期格式
    int format = 0;
    if (s.find('/') == string::npos)
    {
        format=1;
    }
    //第一种日期处理函数
    if (!format)
    {
        auto symbol_pos1 = s.find('/');
        string m = s.substr(0 ,symbol_pos1);
        month=std::stoi(m);
        auto symbol_pos2 = s.find('/' , symbol_pos1+1);
        int len = symbol_pos2-symbol_pos1-1;
        string d = s.substr(symbol_pos1+1 , len);
        day = std::stoi(d);
        string y = s.substr(symbol_pos2+1);
        year = std::stoi(y);
    }
    else
    {
        //第二三种日期格式处理
        auto symbol_pos1=s.find(' ');
        string m = s.substr(0 ,symbol_pos1);
        //处理月份
        if( m.find("Jan")!= string::npos)  month = 1;
        if(m.find("Feb")!= string::npos) month=2;
        if(m.find("Mar")!= string::npos) month=3;
        if(m.find("Apr")!= string::npos) month=4;
        if(m.find("May")!= string::npos) month=5;
        if(m.find("Jun")!= string::npos) month=6;
        if(m.find("Jul")!= string::npos) month=7;
        if(m.find("Aug")!= string::npos) month=8;
        if(m.find("Sep")!= string::npos) month=9;
        if(m.find("Oct")!= string::npos) month=10;
        if(m.find("Nov")!= string::npos) month=11;
        if(m.find("Dec")!= string::npos) month=12;
        //处理日期
        auto symbol_pos2 = s.find(' ' , symbol_pos1+1);
        size_t len = 1;
        if( symbol_pos2-symbol_pos1-1 >=2 ) len=2;
        string d = s.substr(symbol_pos1+1 , len);
        day = std::stoi(d);
        string y = s.substr(symbol_pos2+1,s.size()-symbol_pos2-1);
        year = std::stoi(y);
    }  
}