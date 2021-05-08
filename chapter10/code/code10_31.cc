#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
int main(){
    istream_iterator<int> int_in(cin) , int_eof;
    vector<int> vec(int_in , int_eof);
    sort(vec.begin() ,vec.end());
    ostream_iterator<int> int_out(cout , " ");
    /*练习10.30*/
    // copy(vec.cbegin() , vec.cend() , int_out);
    /*练习10.31*/
    unique_copy(vec.cbegin() , vec.cend() , int_out);
    return 0;
}
