#include "Screen.cc"
#include <iostream>
using std::cout;

int main(){
    Screen myScreen(5,5);
    myScreen.move(4,0).set('*').display(cout);
    /*习题7.32👇*/
    // Window_mgr window_mgr;
    // window_mgr.push_in(myScreen);
    // window_mgr.clear(1);
    /*习题7.32👆*/
    cout<<std::endl;
    myScreen.display(cout);
    cout<<std::endl;
    return 0;
}