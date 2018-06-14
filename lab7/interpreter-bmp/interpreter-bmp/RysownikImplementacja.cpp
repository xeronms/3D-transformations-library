#include "Rysownik.h"
#include "bmp.h"
#include "Interpreter.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace JiMP2;


void RysownikImplementacja::printl(BMP& bmp, uint16_t  x1, uint16_t y1, uint16_t x2, uint16_t y2, unsigned char r, unsigned char g, unsigned char b)const{
        double deltax = x2-x1;
        double deltay = y2-y1;

        if (abs(deltay) > abs(deltax)){
                if (y1 > y2) 	printl(bmp,y2, x2, y1, x1,r,g,b);
                else	 printl(bmp,y1, x1, y2, x2, r,g,b);
        }
        else{
                if (x1 > x2)	 printl(bmp,x2,y2,x1,x2,r,g,b);
                else{
                        uint16_t x, y;
                        y = y1;
                        double deltaerr = abs(deltay/deltax);
                        double error = 0;
                        for (x=x1; x<=x2; ++x){
                                bmp.setPixel(x,y,r,g,b);
                                error += deltaerr;
                                while (error >= 0.5){
                                        y += ((deltay > 0) ? 1 : -1);
                                        error -= 1;
                                }
                        }
                }
        }
}

void RysownikImplementacja::circleEmpty(BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b)const{
    int x = rad-1, y = 0;
    int dx = 1, dy = 1;
    int err = dx - (rad << 1);

    while (x >= y){
        bmp.setPixel(x0 + x, y0 + y, r,g,b);
        bmp.setPixel(x0 + y, y0 + x, r, g ,b);
        bmp.setPixel(x0 - y, y0 + x, r, g ,b);
        bmp.setPixel(x0 - x, y0 + y, r, g ,b);
        bmp.setPixel(x0 - x, y0 - y, r, g ,b);
        bmp.setPixel(x0 - y, y0 - x, r, g ,b);
        bmp.setPixel(x0 + y, y0 - x, r, g ,b);
        bmp.setPixel(x0 + x, y0 - y, r, g ,b);

        if (err <= 0){
                y++;
                err += dy;
                dy += 2;
        }
        if (err > 0){
                x--;
                dx += 2;
                err += dx - (rad << 1);
        }
    }
}

void RysownikImplementacja::circleFilled(BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b)const{
    int x = rad-1, y = 0;
    int dx = 1, dy = 1;
    int err = dx - (rad << 1);

    while (x >= y){
        printl(bmp, x0-y, y0-x,  x0+y, y0-x,  r, g ,b);
        printl(bmp, x0-y, y0+x,  x0+y, y0+x,  r, g ,b);
        printl(bmp, x0-x, y0-y,  x0+x, y0-y,  r, g ,b);
        printl(bmp, x0-x, y0+y,  x0+x, y0+y,  r, g ,b);


        if (err <= 0){
                y++;
                err += dy;
                dy += 2;
        }
        if (err > 0){
                x--;
                dx += 2;
                err += dx - (rad << 1);
        }
    }
}

