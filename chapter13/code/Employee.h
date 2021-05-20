#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using std::string;
class Employee
{
private:
    string name;
    size_t ID;
    static size_t genID;
public:
    Employee()=default;
    Employee(const string &s):name(s),ID(genID++){}
    Employee(const Employee &emp)=delete;
    Employee& operator=(const Employee& emp)=delete;
};
#endif