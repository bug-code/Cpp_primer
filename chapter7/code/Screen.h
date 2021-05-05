#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>
using std::string;
using std::ostream;

class Screen
{
public:
    using pos =string::size_type;
    Screen()=default; 
    Screen(pos ht , pos wd , char c);
    Screen(pos ht , pos wd );
    ~Screen();
    /*返回光标处内容*/
    char getContent() const;
    /*重载，返回指定位置处的内容*/
    char getContent(pos ht, pos wd ) const;
    void setContent(string);
    pos getHight() const;
    pos getWidth() const;
    /*移动光标*/
    Screen &move(pos r , pos c);
    Screen &set(char );
    Screen &set(pos , pos , char);

    /*常量对象的display函数*/
    Screen &display(ostream &os);

    const Screen &display(ostream &os) const;


private:
    pos cursor=0;
    pos hight=0, width=0 ;
    string content;
    void do_display(ostream &os) const;
};

#endif
