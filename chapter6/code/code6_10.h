#ifndef CODE6_10_H
#define CODE6_10_H
void ptr_swap(int *ptr1,int *ptr2){
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
};
#endif