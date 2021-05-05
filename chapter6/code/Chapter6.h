/*第六章声明头文件*/
#ifndef CHAPTER6_H
#define CHAPTER6_H

#include <string>
#include <iostream>
#include <iterator>

#include "fact.h"
#include "interact_fact.h"
#include "absolut.h"
#include "call_times.h"
#include "code6_10.h"
#include "code6_11.h"
#include "code6_12.h"
#include "code6_17.h"
#include "code6_21.h"
#include "code6_22.h"
#include "code6_23.h"
#include "code6_27.h"
#include "code6_33.h"
#include "code6_38.h"
#include "code6_42.h"
#include "code6_51.h"

/*练习6.44*/
inline  bool isShorter(const std::string &s1 , const std::string &s2 ){
    return s1.size() < s2.size(); //非字面值类型
};

using std::string ;
using std::cout;
using std::cin;
using std::endl;
using std::vector;



#endif