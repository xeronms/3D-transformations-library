#include "Rysownik.h"
#include "bmp.h"
#include "Interpreter.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace JiMP2;


void RysownikImplementacja::printl(JiMP2::BMP &bmp,uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, unsigned char r, unsigned char g, unsigned char b) const {
	if( abs(y2-y1)<abs(x2-x1)){
		if(x1>x2){
			std::swap(x1,x2);
			std::swap(y1,y2);
		}
		float xx=x2-x1;
		float yy=y2-y1;
		int yi=1;
		if(yy<0){
			yi=-1;
			yy=-yy;
		}
		float dd=yy*2-xx;
		int j=y1;
		for(int i=x1; i<=x2; ++i){
			bmp.setPixel(i,j,r,g,b);
			if( dd>0){
				j+=yi;
				dd-=xx*2;
			}
			dd+=yy*2;
		}
	}
	else{
		if(y1>y2){
			std::swap(x1,x2);
			std::swap(y1,y2);
		}
		float xx=x2-x1;
		float yy=y2-y1;
		int xi=1;
		if(xx<0){
			xi=-1;
			xx=-xx;
		}
		float dd=yy*2-xx;
		int k=x1;
		for(int l=y1; l<=y2;++l){
			bmp.setPixel(k,l,r,g,b);
			if( dd>0){
				k+=xi;
				dd-=yy*2;
			}
			dd+=xx*2;
		}
 	}
}
void RysownikImplementacja::circleEmpty(JiMP2::BMP &bmp,uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b) const {
	int x=rad-1;
	int y=0;
	int xx=1;
	int yy=1;
	int a=xx-rad*2;
	while (x>=y){
		bmp.setPixel(x0+x,y0+y,r,g,b);
		bmp.setPixel(x0+x,y0-y,r,g,b);
       	bmp.setPixel(x0+y,y0+x,r,g,b);
       	bmp.setPixel(x0+y,y0-x,r,g,b);
       	bmp.setPixel(x0-x,y0+y,r,g,b);
       	bmp.setPixel(x0-x,y0-y,r,g,b);
       	bmp.setPixel(x0-y,y0+x,r,g,b);
       	bmp.setPixel(x0-y,y0-x,r,g,b);
       	if (a<=0){
           	a+=yy;
           	yy+=2;
           	++y;
       	}
       	if (a>0){
       		a+=xx-(rad*2);
           	xx+=2;
           	--x;      	
        }
	}
}
void RysownikImplementacja::circleFilled(JiMP2::BMP &bmp,uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b) const {
		int x=rad-1;
		int y=0;
		int xx=1;
		int yy=1;
		int a=xx-rad*2;
		while (x>=y){
			printl(bmp,x0-y,y0-x,x0+y,y0-x,r,g,b);
			printl(bmp,x0-x,y0-y,x0+x,y0-y,r,g,b);
        	printl(bmp,x0-y,y0+x,x0+y,y0+x,r,g,b);
        	printl(bmp,x0-x,y0+y,x0+x,y0+y,r,g,b);
       		if (a<=0){
            	a+=yy;
            	yy+=2;
            	++y;
        	}
        	if (a>0){
            	xx+=2;
            	a+=xx-rad*2;
            	--x;
        	}
		}
	}

void RysownikImplementacja::archEmpty(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, uint16_t beg, uint16_t end, unsigned char r, unsigned char g, unsigned char b) const {

    double i=0;
    while(i<2*3.14){
        if(i*180/3.14>=beg&&i*180/3.14<=end){
                if((x0+int(sin(i)*(rad)))<bmp.w && (y0-int(cos(i)*(rad)))<bmp.h){
                    bmp.setPixel(x0+int(sin(i)*(rad)), y0-int(cos(i)*(rad)), r,g,b);
                }
            }
		i+=0.001;
    }
}


void RysownikImplementacja::archFilled(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, uint16_t beg, uint16_t end, unsigned char r, unsigned char g, unsigned char b) const {

    for(int j=rad;j>=0;j--){
        double i=0;
        while(i<2*3.14){
            if(i*180/3.14>=beg&&i*180/3.14<=end){
                if((x0+int(sin(i)*(rad-j)))<bmp.w && (y0-int(cos(i)*(rad-j)))<bmp.h){
                    bmp.setPixel(x0+int(sin(i)*(rad-j)), y0-int(cos(i)*(rad-j)), r,g,b);
                }
            }
            i+=0.001;
        }
    }
}