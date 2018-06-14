#include "bmp.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>


using namespace std;

namespace JiMP2 {

BMP::BMP(uint16_t width, uint16_t height) :
		bitmapCoreHeader(width, height) {

	assert(IS_LITTLE_ENDIAN);
	assert(width > 0);
	assert(height > 0);

	const unsigned int rowSize = ((bitmapCoreHeader.bitsPerPixel * width + 31)
			/ 32) * 4;
	const unsigned int imgSize = rowSize * height;

	bmpFileHeader.size = 14 + bitmapCoreHeader.size + imgSize;
	bmpFileHeader.dataOffset = 14 + bitmapCoreHeader.size;

	pixelData = new unsigned char[imgSize];
	std::memset(pixelData, 255, imgSize);
}

BMP::~BMP() {
	delete[] pixelData;
}

void BMP::setPixel(uint16_t x, uint16_t y, unsigned char r, unsigned char g,
		unsigned char b) {
	assert(bitmapCoreHeader.bitsPerPixel == 24);

	const size_t rowSize = ((bitmapCoreHeader.bitsPerPixel
			* bitmapCoreHeader.bmpWidth + 31) / 32) * 4;
	const size_t offset = rowSize * (bitmapCoreHeader.bmpHeight - y)
			+ x * (bitmapCoreHeader.bitsPerPixel / 8);

	pixelData[offset + 0] = b;
	pixelData[offset + 1] = g;
	pixelData[offset + 2] = r;
}

std::ostream& operator<<(std::ostream& os, const BMP& bmp) {
	os.write(bmp.bmpFileHeader.id, sizeof(bmp.bmpFileHeader.id));
	os.write((const char*) &bmp.bmpFileHeader.size,
			sizeof(bmp.bmpFileHeader.size));
	os.write(bmp.bmpFileHeader.reserved, sizeof(bmp.bmpFileHeader.reserved));
	os.write((const char*) &bmp.bmpFileHeader.dataOffset,
			sizeof(bmp.bmpFileHeader.dataOffset));

	os.write((const char*) &bmp.bitmapCoreHeader.size,
			sizeof(bmp.bitmapCoreHeader.size));
	os.write((const char*) &bmp.bitmapCoreHeader.bmpWidth,
			sizeof(bmp.bitmapCoreHeader.bmpWidth));
	os.write((const char*) &bmp.bitmapCoreHeader.bmpHeight,
			sizeof(bmp.bitmapCoreHeader.bmpHeight));
	os.write((const char*) &bmp.bitmapCoreHeader.colorPlanes,
			sizeof(bmp.bitmapCoreHeader.colorPlanes));
	os.write((const char*) &bmp.bitmapCoreHeader.bitsPerPixel,
			sizeof(bmp.bitmapCoreHeader.bitsPerPixel));

	const unsigned int rowSize = ((bmp.bitmapCoreHeader.bitsPerPixel
			* bmp.bitmapCoreHeader.bmpWidth + 31) / 32) * 4;
	const unsigned int imgSize = rowSize * bmp.bitmapCoreHeader.bmpHeight;

	os.write((const char*) bmp.pixelData, imgSize);

	return os;
}


void BMP::printl(uint16_t  x1, uint16_t y1, uint16_t x2, uint16_t y2, unsigned char r, unsigned char g, unsigned char b){
	double deltax = x2-x1;
	double deltay = y2-y1;

	if (abs(deltay) > abs(deltax)){
		if (y1 > y2) 	printl(y2, x2, y1, x1,r,g,b);
		else	 printl(y1, x1, y2, x2, r,g,b);
	}
	else{
		if (x1 > x2)	 printl(x2,y2,x1,x2,r,g,b);
		else{
			uint16_t x, y;
			y = y1;
			double deltaerr = abs(deltay/deltax);
			double error = 0;
			for (x=x1; x<=x2; ++x){
				setPixel(x,y,r,g,b);
				error += deltaerr;
				while (error >= 0.5){
					y += ((deltay > 0) ? 1 : -1);
					error -= 1;
				}		
			}
		}
	}
}

void BMP::circleEmpty(uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b){
    int x = rad-1, y = 0;
    int dx = 1, dy = 1;
    int err = dx - (rad << 1);

    while (x >= y){
        setPixel(x0 + x, y0 + y, r,g,b);
        setPixel(x0 + y, y0 + x, r, g ,b);
        setPixel(x0 - y, y0 + x, r, g ,b);
        setPixel(x0 - x, y0 + y, r, g ,b);
        setPixel(x0 - x, y0 - y, r, g ,b);
        setPixel(x0 - y, y0 - x, r, g ,b);
        setPixel(x0 + y, y0 - x, r, g ,b);
        setPixel(x0 + x, y0 - y, r, g ,b);

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

void BMP::circleFilled(uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b){
    int x = rad-1, y = 0;
    int dx = 1, dy = 1;
    int err = dx - (rad << 1);

    while (x >= y){
        printl(x0-y, y0-x,  x0+y, y0-x,  r, g ,b);
        printl(x0-y, y0+x,  x0+y, y0+x,  r, g ,b);
        printl(x0-x, y0-y,  x0+x, y0-y,  r, g ,b);
        printl(x0-x, y0+y,  x0+x, y0+y,  r, g ,b);


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



}
/*
int main() {

	const uint16_t imgWidth = 800;
	const uint16_t imgHeight = 600;

	JiMP2::BMP bmp(imgWidth, imgHeight);

	bmp.printl(511,500,300,180,255,0,0);
	bmp.printl(411,0,0,180,255,0,0);
	bmp.printl(11,500,0,180,255,0,0);
	bmp.printl(511,50,50,50,255,50,50);
        bmp.circleFilled(550,400,50,255,0,0);
        bmp.circleEmpty(140,300,100,255,0,0);
	
	std::ofstream outfile("test.bmp", std::ofstream::binary);
	outfile << bmp;

	std::cout << "end." << std::endl;

	return 0;
}
*/
