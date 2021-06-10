#ifndef BEG_END_H
#define BEG_END_H
template<typename T , unsigned U> T* mybegin(T (&arr)[U]){
    return arr;
}

template<typename T , unsigned U> T* myend( T (&arr)[U]){
    return arr+U;
}
#endif