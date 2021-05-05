#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream; 
using std::endl;
class Person
{
    friend istream &read(std::istream &is , Person &P);
    private:
        string Name;
        string adress;
        
    public:
        Person()=default;
        Person(string &s , string &add):Name(s),adress(add){}
        explicit Person(string &s ):Name(s){}
        Person(istream &is){
            read(is , *this);
        }

        ~Person();
        string getName()const{return Name; }
        string getAdress() const { return adress;}
};
//非成员函数声明
istream &read(istream &, Person & );
ostream &print(ostream & , const Person &);


//非成员函数定义
istream &read(std::istream &is , Person &P){
    is>>P.Name>>P.adress;
    return is;
}

ostream &print(ostream &os , const Person &P){
    os<<P.getName()<<" "<<P.getAdress()<<endl;
    return os;
}





#endif