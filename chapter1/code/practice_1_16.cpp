#include <iostream>
int main(){
    int var1=0,sum=0;
    while (std::cin>> var1)
    {
        sum+=var1;
    }
    std::cout<< sum<<std::endl;
    return 0;
}