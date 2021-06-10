#include <iostream>
#include "compare.h"
#include "Sales_data.h"
#include "myFind.h"
#include "myPrint.h"
#include "beg_end.h"
#include "mySize.h"
#include "Blob.h"
#include "Vec.h"
#include <vector>
#include <list>
#include <string>
int main(){
    /*练习16.2*/
    // std::cout<<compare(1 , 2)<<std::endl;
    // std::cout<<compare("a"  , "b")<<std::endl;
    /*显式指定类型参数*/
    // std::cout<<compare<std::string>("fuck" , "you")<<std::endl;
    /*练习16.3*/
    // Sales_data data1("aaa" , 10 , 20.0);
    // Sales_data data2("bbb" , 27 , 14.2);
    // std::cout<<compare(data1 , data2)<<std::endl;
    /*练习16.4*/
    // std::vector<int> vec{1,2,3,4,56,98};
    // std::list<std::string> ilst{"fuck" , "you" , "mother" , "fucker" };
    // std::cout<<*myFind(vec.cbegin() , vec.cend() , 56)<<std::endl;
    // std::cout<<*myFind(ilst.cbegin() , ilst.cend() , "you")<<std::endl;
    /*练习16.5*/
    // char arr[]{'f','u','c','y','u'};
    // myprint(arr);
    /*练习16.6*/
    // std::cout<<*mybegin(arr)<<std::endl;
    // std::cout<<*myend(arr)<<std::endl;
    /*练习16.7*/
    // std::cout<<mysize(arr)<<std::endl;

    // Blob<int> intBlob1{0,1,2,3,4};
    // Blob<int> intBlob2{5,6,7,8,9};
    // intBlob1.push_back(5);
    // // std::cout<<intBlob1[5];
    // std::cout<< (intBlob1<intBlob2) <<std::endl;

    /*Vec测试*/
    // Vec<int> v1{1,2,24,5,6};
    // v1.push_back(5);
    // v1.pop_back();
    // std::cout<<v1.size()<<" "<<v1.capacity()<<" "<<v1[0]<<std::endl;
    // for (auto  beg = v1.cbegin() , en = v1.cend(); beg!=en; ++beg)
    // {
    //     std::cout<<*beg<<" ";
    // }

    /*练习16.37*/
    std::cout<<std::max<float>(10.2,23)<<std::endl;
    
    return 0;    
}