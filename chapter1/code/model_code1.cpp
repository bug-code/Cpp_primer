#include <iostream>
/*
对输入的要求：不要求有序，但相同数字都在一起
*/
int main(){
    int currVal = 0 ,val=0;
    if (std::cin>>currVal)
    {
        int cnt=1;
        while (std::cin>>val)
        {
            if (val==currVal)
            {
                ++cnt;
            }
            else
            {
                std::cout<<currVal<<"\40occurs\40"
                        <<cnt<<"\40times"<<std::endl;
                currVal = val;
                cnt=1;
             }
        }
        std::cout<<currVal<<"\40occurs\40"
                <<cnt<<"\40times"<<std::endl;
    }
    return 0;    
    
}