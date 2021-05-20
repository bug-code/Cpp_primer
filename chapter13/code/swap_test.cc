// #define NDEBUG
#include "Foo.h"
int main(){
    HasPtr hp1("fuck") , hp2("you");
    Foo f1(hp1) , f2(hp2);
    swap(f1 , f2);
}

