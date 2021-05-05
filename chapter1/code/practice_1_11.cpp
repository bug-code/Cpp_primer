#include <iostream>
int main(){
    std::cout<< "Input two inter :"<< std::endl;
    int var1 = 0,var2=0;
    std::cin>> var1 >> var2 ;
    
    if (var1==var2)
    {
        std::cout<< var1 << "\40" << std::endl;
    }
    else
    {
        while (var1!=var2)
        {
            std::cout<< var1 << '\40';
            if (var1 >=var2)
            {
                --var1;
            }
            else
            {
                ++var1;
            }
        }
    }
    return 0;   
}