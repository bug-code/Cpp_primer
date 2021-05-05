#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::ifstream;
using std::string;
using std::vector;
using std::getline;
void vec_add_file(vector<string> &vec ,const string &f){
    ifstream fstrm(f );
    if (fstrm)
    {
        string s;
        while (getline(fstrm ,s ))
        {
            vec.push_back(s);
        }
    }
}

void vec_add_word(vector<string> &vec ,const string &f){
    ifstream fstrm(f , ifstream::in);
    if (fstrm)
    {
        string s;
        while (fstrm >> s)
        {
            vec.push_back(s);
        }
    }
}

void vec_print(const vector<string> &vec){
    for (const auto &i : vec)
    {
        std::cout<<i<< " " ;
    }
    std::cout<<std::endl;    
}

int main(){
    vector<string> fvec , wvec;
    string filename="F:\\code\\C++_code\\C++ note\\Cpp_primer\\ch8_IO\\code\\poetry.txt";
    vec_add_file(fvec , filename);
    vec_add_word(wvec , filename);
    vec_print(wvec);
    return 0;
}