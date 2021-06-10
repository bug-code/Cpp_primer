#ifndef DEBUGDELETE
#define DEBUGDELETE
#include <iostream>
class DebugDelete{
    private:
        std::ostream &os;
    public:
        DebugDelete(std::ostream &s = std::cerr):os(s){}
        template<typename T> void operator()(T *p){
            os<<"deleting unique_ptr" << std::endl;
            delete p;
        }
};
#endif