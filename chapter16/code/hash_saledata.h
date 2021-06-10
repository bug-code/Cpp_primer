#ifndef HASH_SALEDATA_H
#define HASH_SALEDATA_H
#include "Sales_data.h"
#include <set>
namespace std{
    template<> class hash<Sales_data>{
        public:
            typedef size_t result_type;
            typedef Sales_data argument_type;
            size_t operator()(const Sales_data& s)const;
    };
    size_t hash<Sales_data>::operator()(const Sales_data& s)const{
        return hash<string>()(s.bookNo);
    }
}

#endif