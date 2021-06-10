#ifndef MYSIZE_H
#define MYSIZE_H
template<typename T  ,unsigned U> constexpr unsigned mysize(T (&arr)[U]){
    return U;
}
#endif