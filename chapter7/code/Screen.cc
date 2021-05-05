#include "Screen.h"

Screen::Screen(pos ht , pos wd , char c):hight(ht) , width(wd) , content(ht*wd , c){}

Screen::Screen(pos ht , pos wd ):Screen(ht , wd ,' ' ){}

Screen::~Screen(){}
 
Screen& Screen::display(ostream &os){
    do_display(os);
    return *this;
}

const Screen& Screen::display(ostream &os) const{
    do_display(os);
    return *this;
}



void Screen::do_display(ostream &os) const{
    os<<content<<std::endl;
}


char Screen::getContent() const{
    return content[cursor];
}

char Screen::getContent(pos ht, pos wd ) const{
    pos row = ht*width;
    return content[row+wd];
}
void Screen::setContent(string s){
    content = s;
}
Screen::pos Screen::getHight() const{
    return hight;
}

Screen::pos Screen::getWidth() const{
    return width;
}

inline Screen& Screen::move(pos r, pos c){
    pos row=r*width;
    cursor = row+c;
    return *this;
}

inline Screen& Screen::set(char c){
    content[cursor]=c;
    return *this;
}
inline Screen& Screen::set(pos r , pos col , char c ){
    content[r*width+col] = c;
    return *this;
}
