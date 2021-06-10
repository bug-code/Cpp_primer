#include "Query.h"
#include "myTextQuery.h"
#include "OrQuery.h"
#include <fstream>
#include <iostream>
int main(){
    std::ifstream file("storyDataFile.txt");

    myTextQuery tQuery(file);

    std::cout<<Query("hundred") ;

    return 0;
}