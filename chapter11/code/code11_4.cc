#include <string>
#include <map>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;
const string words_deal(const string s){
    string word;
    for_each(s.cbegin() , s.cend() , [&word](const char &c){if(isalpha(c)) word+=tolower(c);} );
    return word;
}

int main(){
    map<string , size_t> words_count;
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter11\\code\\words.txt");
    ifstream ifs(fileName);
    if (ifs)
    {
        istream_iterator<string> str_in(ifs) , str_eof;
        for_each(str_in , str_eof , [&words_count](const string &s){ string w=words_deal(s) ;++words_count[w];});
        /*练习11.20*/
        // for_each(str_in , str_eof , [&words_count](const string &s){ string w=words_deal(s) ;++words_count.insert({w,0}).first->second;});

        for_each(words_count.cbegin() , words_count.cend() , [](decltype(*(words_count.cbegin())) &word ){ cout<<word.first<<" occurs "<<word.second<<( (word.second > 1) ? " words" :" word")<<endl;});
    }
    else
    {
        cerr<<"hey fuck you. you stupid mother fucker asshole, open file failed.";
    }
    
}