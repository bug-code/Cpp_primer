#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "F:\\code\\C++_code\\C++ note\\Cpp_primer\\ch7_class\\code\\Sales_data.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::vector;
using std::endl;
using std::getline;

int main(int argc , char *argv[]){
    //读取文件名，第二个参数开始
    ifstream ifstrm(argv[1] , ifstream::in);
    //写入的文件名，第三个参数
    ofstream output(argv[2], ofstream::app);
    while (ifstrm)
    {
        Sales_data item;
        read(ifstrm , item);       
        output<<item.isbn()<<" "<<item.sold_units()<<" "<<item.ave_price()<<endl;
    }
    ifstrm.close();
    output.close();
    return 0;
}