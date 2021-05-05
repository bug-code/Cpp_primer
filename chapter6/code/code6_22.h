#ifndef CODE6_22_H
#define CODE6_22_H
void swap_ptr(int *&ptr1 ,  int *&ptr2){
    auto tmp = ptr1;
    ptr1 = ptr2;
    ptr2=tmp;
};
#endif