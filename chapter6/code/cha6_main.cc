#include "Chapter6.h"

int main(){

    /*习题6.10*/
    // int num1=11,*ptr1=&num1,num2=22,*ptr2=&num2;
    // ptr_swap(ptr1,ptr2);
    // std::cout<< num1 <<" "<<num2<<std::endl;

    /*习题6.11*/
    // std::string str = "your mom is dead";
    // myreset(str);
    // std::cout<<str<<std::endl;
    
    /*习题6.12*/
    // int num1=11,num2=22;
    // ref_swap(num1 ,num2 );
    // std::cout<<num1<<" " <<num2<<std::endl;

    /*习题6.17*/
    // std::string str="your mom is Dead";
    // // std::cin>>str;
    // std::cout<<"string has upper alpha?: "<<has_upper(str)<<std::endl;
    // string_to_lower(str);
    // std::cout<<str<<std::endl;

    // /*习题6.21*/
    // int val=10;
    // int arr[]={10,20,5};
    // int *ptr=arr;
    // std::cout<<int_compare(val,(ptr+1))<<std::endl;

    /*习题6.22*/
    // int val1=10 , *ptr1=&val1 , val2=20, *ptr2=&val2;
    // ptr_swap(ptr1,ptr2);
    // std::cout<<*ptr1<<" "<< *ptr2<<std::endl;

    /*习题6.23*/
    // int i=0,j[2]={0,1};
    // auto beg = std::begin(j);
    // auto end = std::end(j);
    // my_print(i , beg , end);

    /*习题6.27*/
    // std::cout<< add_param_list({1,2,3,4,5})<<std::endl;
    // std::cout<< add_param_list({6,7,8,9})<<std::endl;

    /*习题6.33*/
    // std::vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    // auto beg = vec.begin() , end=vec.end();
    // recurs_print(beg , end);

    /*习题6.38*/
    // for (auto &i : arrRef(1))
    // {
    //     std::cout<<i<<" ";
    // }
    
    /*习题6.38*/
    // std::cout<<make_plural(1,"success","es")<<std::endl<<make_plural(2,"failure");

    /*习题6.44*/
    // string s1="abc";
    // string s2="ab";
    // cout<<isShorter(s1,s2)<<endl; 

    /*习题6.51*/
    f(2.56,3.14);


}