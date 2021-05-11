#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <functional>
using namespace std;
using namespace std::placeholders;

const string words_deal(const string s){
    string word;
    for_each(s.cbegin() , s.cend() , [&word](const char &c){if(isalpha(c)) word+=tolower(c);} );
    return word;
}

void save_Norepeat_words(vector<string> &Wvec , const string &word){
    string w = words_deal(word);
    if (find(Wvec.cbegin() , Wvec.cend() , w) == Wvec.cend() )
    {
        Wvec.push_back(w);
    }
}

int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter11\\code\\words.txt");
    ifstream ifs(fileName);
    vector<string> words;
    if (ifs)
    {
        istream_iterator<string> str_in(ifs) , str_eof;
        for_each(str_in , str_eof ,bind(save_Norepeat_words , ref(words) ,_1) );
        for_each(words.cbegin() , words.cend() , [](const string &s){cout<<s<<" ";});
    }
    else
    {
        cerr<<"hey open file failed duchbag!"<<endl;
    }
    
    return 0;
}