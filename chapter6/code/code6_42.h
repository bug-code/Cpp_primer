#ifndef CODE6_42_H
#define CODE6_42_H
#include <string> 
std::string make_plural(size_t ctr , const std::string &word , const std::string &ending="s"){
    return (ctr>1) ? word+ending : word;
    };
#endif