#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::string;
using std::sort;
using std::ifstream;
using std::stable_sort;
bool isShorter(const string &s1,const string &s2){
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words){
    /*练习10.9*/
    sort(words.begin() , words.end());//按字典序排序words，以便查找重复单词。
    auto end_unique = unique(words.begin() , words.end());//unique重排输入范围，返回指向不重复区域之后一个位置的迭代器。
    words.erase(end_unique , words.end());//删除end_unique至最后的的重复元素。
    words.shrink_to_fit();
    /*练习10.11 按长度排序，相同长度按字典顺序*/
    stable_sort(words.begin() , words.end() , isShorter);
}
void addToVec(vector<string> &vecStr , const string &fileName){
    ifstream ifs(fileName);
    if (ifs)
    {
        string word;
        while (ifs>>word)
        {
            vecStr.push_back(word);
        }
    }
    else
    {
        std::cerr<<"open failed"<<endl;
    }
}
void printVecStr(const vector<string> &vecStr){
    for (auto &i : vecStr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}




int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\words.txt");
    vector<string> words;
    addToVec(words , fileName);
    vector<string> words2(words);
    /*按字典顺序排序*/
    elimDups(words);
    printVecStr(words);
    /*按长度排序，相同长度按字典顺序*/
    // stable_sort(words.begin() , words.end() , isShorter);
    // printVecStr(words);

    /*按长度排序*/
    sort(words2.begin() , words2.end() , isShorter);
    printVecStr(words2);

    return 0;
}