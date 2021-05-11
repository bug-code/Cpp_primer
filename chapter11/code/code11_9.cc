#include <map>
#include <list>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*按字典顺序比较单词大小*/
bool compareStr(const string &s1 , const string  &s2){
    //前提字符串都是小写
    auto s1_beg = s1.cbegin() , s1_end=s2.cend();
    auto s2_beg = s2.cbegin() , s2_end=s2.cend();
    while (s1_beg!=s1_end && s2_beg!=s2_end)
    {
        if (*s1_beg != *s2_beg )
        {
            return *s1_beg < *s2_beg;
        }
        else
        {
            ++s1_beg;
            ++s2_beg;
        }
    }
    return s1.size()<s2.size();
}

const string words_deal(const string s){
    string word;
    for_each(s.cbegin() , s.cend() , [&word](const char &c){if(isalpha(c)) word+=tolower(c);} );
    return word;
}

void word_line(istream &is , map<string , list<int>, decltype(compareStr)*> &WL){
    string line;
    int Iline=0;
    while (getline(is,line))
    {
        ++Iline;
        string word;
        istringstream iss(line);
        while (iss>>word)
        {
            string w = words_deal(word);
            if ( WL.find(w) != WL.cend())
            {
                if (find(WL[w].cbegin() , WL[w].cend() , Iline) == WL[w].cend() )
                {
                    WL[w].push_back(Iline);
                    WL[w].sort();
                }
            }
            else
            {
                WL[w].push_back(Iline);
            }   
        }
    }
}

void printmap(map<string  , list<int>, decltype(compareStr)*> &wL){
    for (auto &i : wL)
    {
        cout<<i.first<<": ";
        for (auto &j : i.second)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


int main(){
    map<string  , list<int>, decltype(compareStr)*> wordL(compareStr); 
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter11\\code\\hundredMiles.txt");
    ifstream ifs(fileName);
    if (ifs)
    {
        word_line(ifs,wordL);
        printmap(wordL);
    }
    else
    {
        cerr<<"open file failed, go fuck yourself"<<endl;
    }
}