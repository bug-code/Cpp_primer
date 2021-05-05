#ifndef CODE6_37_H
#define CODE6_37_H
#include <string>
using std::string;
string (*str_func1(string &str))[10];

using str_arrPtr_10 = string [10];
str_arrPtr_10* str_func2(string &str);

auto str_func3(string &str)->string (*)[10];

string arrStr[10];
decltype(arrStr)* str_func4(string &str);

#endif