#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;
//练习9.43
void myReplace(string &s ,const string &oldVal ,const string &newVal){
    size_t pos = 0;
    for (auto s_begin = s.begin() , s_end = s.end(); s_begin!=s_end; ++s_begin)
    {
        auto oldVal_begin = oldVal.cbegin() , oldVal_end=oldVal.cend();
        auto match_iter = s_begin;
        bool notMatch = true;
        while (oldVal_begin!=oldVal_end)
        {
            if (*match_iter != *oldVal_begin)
            {
                notMatch = true;
                break;
            }
            else
            {
                ++match_iter;
                ++oldVal_begin;
                notMatch=false;
            }
            
        }
        if (!notMatch)
        {
            s.insert(match_iter , newVal.cbegin() , newVal.cend());
            s.erase(pos , oldVal.size());
            s_begin = s.begin()+pos+newVal.size();
            if (pos+newVal.size() >= s.size())
            {
                break;
            }           
            pos=pos+newVal.size()+1;   
        }
        else
        {
            ++pos;
        }
        
    }   
}
//练习9.44
void myNewReplace(string &s  , const string &oldVal , const string &newVal ){
    size_t index = 0;
    while (index < s.size())
    {
        if (s.substr(index , oldVal.size())==oldVal)
        {
            s.replace(index , oldVal.size() , newVal );
            index += newVal.size();
        }
        else
        {
            ++index;
        }
    }
}

//test
int main(){
    string s("tho you mother fucker tho fuck you tho") , oldStr("tho") , newStr("though");
    // myReplace(s , oldStr , newStr);
    myNewReplace(s , oldStr , newStr);
    cout<<s<<endl;
    return 0;
}