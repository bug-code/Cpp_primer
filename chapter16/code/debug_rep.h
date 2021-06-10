#ifndef DEBUG_REP_H
#define DEBUG_REP_H
#include <string>
#include <sstream>
/*声明*/
template<typename T> std::string debug_rep(const T &t);
template<typename T> std::string debug_rep(T *t);
std::string debug_rep(const std::string& s);
std::string debug_rep(char *p);
std::string debug_rep(const char *p);
/*定义*/
template<typename T> std::string debug_rep(const T &t){
    std::ostringstream os;
    os << t;
    return os.str();
}
template<typename T> std::string debug_rep(T *t){
    std::ostringstream os;
    os<<"pointer:"<<t;
    if (t)
    {
        os<<" "<<debug_rep(*t);
    }
    else
    {
        os<<" nullptr ";
    }
    return os.str();
}
std::string debug_rep(const std::string& s){
    return " "+ s+" ";
}
std::string debug_rep(char *p){
    return debug_rep(std::string(p));
}
std::string debug_rep(const char *p){
    return debug_rep(std::string(p));
}

/*练习16.65 , 特例版本*/
template<> std::string debug_rep(char* p){
    return debug_rep(std::string(p));
}
template<> std::string debug_rep(const char* p){
    return debug_rep(std::string(p));
}
#endif