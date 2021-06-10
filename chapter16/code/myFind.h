#ifndef MYFIND_H
#define MYFIND_H
#include <stdexcept>
template<typename T , typename V> T myFind( T beg ,  T en , const V& value){
    
        while (*beg != value&& beg!=en){
              ++beg;          
        }
        return  beg;       
}
#endif