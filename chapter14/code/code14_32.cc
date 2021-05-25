#include "StrBlobPtr.cc"
class code14_32
{
private:
    StrBlobPtr *p;
public:
    code14_32( ):p(nullptr){};
    code14_32(StrBlobPtr& ptr):p(&ptr){}
    StrBlobPtr& operator*()const;
    StrBlobPtr* operator->()const;
    ~code14_32();
};

StrBlobPtr& code14_32::operator*()const{
    return  *p; 
}
StrBlobPtr* code14_32::operator->()const{
    return & this->operator*();
}
