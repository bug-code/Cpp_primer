#ifndef DATA_H
#define DATA_H
#include <string>
using std::string;
class date
{
private:
    unsigned year , month , day;
public:
    date() = default;
    date(const string &s);
    ~date()=default;
    unsigned getYear()const {return year;};
    unsigned getMonth()const{return month;};
    unsigned getDay()const{return day;};
};
#endif