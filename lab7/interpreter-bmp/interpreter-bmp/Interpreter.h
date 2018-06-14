
#ifndef _INTERPR_
#define _INTERPR_
#include "bmp.h"
#include "Rysownik.h"
#include <string>

struct file_error{
};

struct line_error{
    int line_no;
    line_error(int i):line_no(i){}
};


class Interpreter{
    float x1,y1,x2,y2,rad;
    unsigned char r,g,b;
    RysownikImplementacja rys;
public:
    Interpreter(){}
    ~Interpreter(){}
    void interpretuj(std::string& sciezka, JiMP2::BMP& bmp);
};

#endif