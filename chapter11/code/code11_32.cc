#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;



const string words_deal(const string s){
    string word;
    for_each(s.cbegin() , s.cend() , [&word](const char &c){if(isalpha(c)) word+=tolower(c);} );
    return word;
}


void readAuthors(istream &is , multimap<string , string > &mmp){
    string line;
    while (getline(is , line))
    {
        string author(line, 0,line.find(':'));
        for (auto beg = line.find(':')+1 , en = line.size() , part_end = beg; beg<en; beg=part_end+1)
        {
            auto  part_beg = line.find('<' , beg)+1;
            part_end = line.find('>' ,beg);
            string production(line , part_beg , part_end-part_beg);
            string w = words_deal(production);
            mmp.insert({author , w});
        }
    }
}
void printmap(const multimap<string , string> &m){
    for (auto &&i : m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    
}

void erasePair(multimap<string , string> &m , const string &author , const string &prod=""){
    if (prod=="")
    {
        m.erase(author);
    }
    else
    {
        auto p=m.equal_range(author);
        while (p.first !=p.second)
        {
            if (p.first->second == prod)
            {
                m.erase(p.first);
                /*删除元素会改变迭代器指向*/
                p=m.equal_range(author);
            }
            else
            {
                ++p.first;
            }
            
        }
    }
}

int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter11\\code\\authors.txt");
    ifstream ifs(fileName);
    multimap<string , string> mp;
    if (ifs)
    {
        readAuthors(ifs,mp);
        // printmap(mp);
        erasePair(mp,"NMSL","fuckyou");
        // printmap(mp);
        erasePair(mp,"NMSL","bitch");
        printmap(mp);
    }
    else
    {
        cout<<"hey fuck you , open file failed mother fucker!"<<endl;
    }
    
    return 0;
}