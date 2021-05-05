#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
//练习9.45
string embellishName( string name , const string &prefix   , const string &suffix){
    name.insert(name.cbegin() , prefix.cbegin() , prefix.cend() );
    name.append(suffix);
    return name;
}
//练习9.46
string newEmbellishName(string name , const string &prefix  ,const string &suffix){
    name.insert(0 , prefix);
    name.insert(name.size() , suffix);
    return name;
}
//test
int main(){
    string name("chris Goudan") , prefix("Mr. ") , suffix(" I");
    // string newName = embellishName(name , prefix , suffix);
    string newName = newEmbellishName(name , prefix , suffix);
    cout<<newName<<endl;
    return 0;

}