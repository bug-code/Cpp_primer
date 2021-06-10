#ifndef COMPARE_H
#define COMPARE_H
template<typename T> int compare(const T& lhs, const T& rhs){
    if(lhs<rhs) return -1;
    if(rhs<lhs) return 1;
    return 0;
}
#endif