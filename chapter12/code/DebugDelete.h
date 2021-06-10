#ifndef DEBUGDELETE
#define DEBUGDELETE
/*练习16.22*/
#include <iostream>
class DebugDelete{
    private:
        std::ostream &os;
    public:
        DebugDelete(std::ostream &s = std::cout):os(s){}
        template<typename T> void operator()(T *p){
            os<<"deleting unique_ptr" << std::endl;
            delete p;
        }
};
#endif