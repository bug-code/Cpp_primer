#ifndef CODE6_17_H
#define CODE6_17_H

#include <string>
bool has_upper(const std::string &str ){
    bool flag=false;
    for ( auto &cha : str)
    {
        if (isalpha(cha))
        {
            if (isupper(cha))
            {
                flag=true;
                break;
            }
        }
    }
    return flag;
    
};

void string_to_lower(std::string &str){
    for ( auto &cha : str)
    {
        cha=tolower(cha);
    }
};
#endif