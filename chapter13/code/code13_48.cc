#include <vector>
#include "String.cc"
int main(){
    char c1[]("fuck");
    char c2[]("you");
    char c3[]("mother");
    char c4[]("fucker");

    char* p1 = c1;
    char* p2 = c2;
    char* p3 = c3;
    char* p4 = c4;
    String s1(p1);
    String s2(p2);
    String s3(p3);
    String s4(p4);

    std::vector<String> vecStr;
    vecStr.push_back(s1);
    vecStr.push_back(s2);
    vecStr.push_back(s3);
    vecStr.push_back(s4);

    return 0;
}