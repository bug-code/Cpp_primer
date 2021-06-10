#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
void addfamily(map<string ,vector<pair<string,size_t>>> &familys , const string &familyName ){
    if (familys.find(familyName) == familys.cend())
    {
        // familys.insert(pair<string , vector<string>>(familyName , vector<string>() ) );
        familys[familyName] = vector<pair<string,size_t>>();
    } 
}

void addFamilyMem(map<string , vector<pair<string,size_t>>> &familys , const string &familyName , const string &MemName , const size_t &birth){
    if (familys.find(familyName) == familys.cend())
    {
        familys[familyName].push_back({MemName,birth});
    }
    else
    {
        if ( find_if(familys[familyName].cbegin() , familys[familyName].cend() , [MemName](const pair<string,size_t> &p){ return p.first==MemName;}) == familys[familyName].cend() )
        {
            familys[familyName].push_back({MemName,birth});
        }
    }
}

void printFamily(const vector<pair<string,size_t>> &Svec){
    for_each(Svec.cbegin() , Svec.cend() , [](const pair<string,size_t> &s){ cout<<s.first<<" "<<s.second<<" ";});
    cout<<endl;
}

int  main(){
    map< string , vector< pair<string,size_t> > > home;
    addfamily(home , "fuck");
    addFamilyMem(home,  "fuck" , "you" , 1000);
    addFamilyMem(home,  "fuck" , "asshole" , 999);
    for_each(home.cbegin() , home.cend() , [](decltype(*home.cbegin()) &h){cout<<h.first<<": ";printFamily(h.second);});


}