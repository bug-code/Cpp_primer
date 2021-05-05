#ifndef FACT_H
#define FACT_H
int fact(int  v1){
    int sum=1;
    while (v1)
        sum *= v1--;
    return sum;
};
#endif