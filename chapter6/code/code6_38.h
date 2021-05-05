#ifndef CODE6_38_H
#define CODE6_38_H
int odd[]={1,3,5,7,9};
int even[]={0,2,4,6,8};
decltype(odd) &arrRef(int i){
    return (i%2) ? odd:even  ;
};

#endif