#include "Debug.h"
constexpr Debug::Debug(bool b=true):hw(b),io(b),others(b){

}

constexpr Debug::Debug(bool h,bool i , bool o ):hw(h) , io(i),others(o){

}
constexpr bool Debug::any(){
    return hw || io||others;
}
void Debug::set_io(bool h){
    hw = h;
}

void Debug::set_io(bool i){
    io =i;
}

void Debug::set_other(bool o){
    others =o;
} 
