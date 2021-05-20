#include <iostream>
using namespace std;
static int NO=0;

class numbered
{
private:
    int mysn;
public:
    /*练习13.14*/
    numbered():mysn(NO++){};
    /*练习13.15*/
    // numbered(const numbered &num):mysn(NO++){}
    int getMysn()const{return mysn;}
};
/*练习13.16*/
void f(const numbered s){cout<<s.getMysn()<<endl;}
int main(){

    numbered a , b=a , c=b;
    f(a);
    f(b);
    f(c);
    return 0;
}
