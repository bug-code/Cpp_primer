#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
class compareLen
{
private:
    /* data */
public:
    bool operator()(const string& s1 , const string& s2){return s1.size() < s2.size(); }
};

class longerThan
{
private:
    vector<string>::size_type sz;    
public:
    longerThan(const vector<string>::size_type& len):sz(len){};
    bool operator()(const string& s){return s.size()>=sz;}
};




void elimDups(vector<string> &words){
    /*练习10.9*/
    sort(words.begin() , words.end());//按字典序排序words，以便查找重复单词。
    auto end_unique = unique(words.begin() , words.end());//unique重排输入范围，返回指向不重复区域之后一个位置的迭代器。
    words.erase(end_unique , words.end());//删除end_unique至最后的的重复元素。
    words.shrink_to_fit();
    stable_sort(words.begin() , words.end() , compareLen());
}




auto mybiggies(vector<string> &vecStr ,const vector<string>::size_type &sz)->vector<string>::const_iterator{
    elimDups(vecStr);
    return find_if(vecStr.cbegin() , vecStr.cend() ,longerThan(sz) );
}

void addToVec(vector<string> &vec , const string &fileName){
    ifstream ifs(fileName);
    if (ifs)
    {
        string s;
        while (ifs>>s)
        {
            vec.push_back(s);
        }
    }
    else
    {
        std::cerr<<"open file failed"<<endl;
    }
}


int main(){
    vector<string> vecStr;
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\words.txt");
    addToVec(vecStr , fileName);
    elimDups(vecStr);
    int sz = 5;
    auto marksPos = mybiggies(vecStr , sz); 
    auto counts = vecStr.cend()-marksPos;
    cout<<counts<<" " << (counts > 1 ? "words":"word")<<" of length "<<sz<<" or longer."<<endl;
    for_each(marksPos , vecStr.cend() , [](const string &s){cout<<s<<" ";});
}