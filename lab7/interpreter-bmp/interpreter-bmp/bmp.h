#ifndef __BMP_H
#define __BMP_H


#include "obj.h"
#include <stdint.h>
#include <iostream>



// define IS_LITTLE_ENDIAN (!!(union { uint16_t u16; unsigned char c; }){ .u16 = 1 }.c)
#define IS_LITTLE_ENDIAN (*(uint16_t *)"\0\xff" > 0x100)

namespace JiMP2 {

/*
 * Informacje o formacie BMP https://en.wikipedia.org/wiki/BMP_file_format
 */

struct BMPFileHeader {
	char id[2];
	uint32_t size;
	char reserved[4];
	uint32_t dataOffset;

	BMPFileHeader() :
			id { 'B', 'M' }, size(0), dataOffset(0) {
		//id[0] = 'B';
		//id[1] = 'M';
	}
};

struct BitmapCoreHeader {
	const uint32_t size;
	const uint16_t bmpWidth;
	const uint16_t bmpHeight;
	const uint16_t colorPlanes;
	const uint16_t bitsPerPixel;

	BitmapCoreHeader(uint16_t width, uint16_t height) :
			size(12), bmpWidth(width), bmpHeight(height), colorPlanes(1),
			bitsPerPixel(24)
	{
	}

};

class BMP {
	BMPFileHeader bmpFileHeader;
	BitmapCoreHeader bitmapCoreHeader;
	unsigned char* pixelData;

public:

	BMP(uint16_t width, uint16_t height);
	virtual ~BMP();

	void setPixel(uint16_t x, uint16_t y, unsigned char r, unsigned char g,
			unsigned char b);


	void printl(uint16_t  x1, uint16_t y1, uint16_t x2, uint16_t y2, unsigned char r, unsigned char g, unsigned char b);
	void circleEmpty(uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b);
	void circleFilled(uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b);

    void print_XY( Obj& ob){

		double s = 100; //skala

        for ( int i = 1; i < ob.face_size(); ++i){
			printl( (ob.get_v(i,1).a + abs(ob.min.a))*s , (ob.get_v(i,1).b + abs(ob.min.b))*s , (ob.get_v(i,2).a + abs(ob.min.a))*s , (ob.get_v(i,2).b + abs(ob.min.b))*s , 0, 0, 0);
        }	
    }
	void print_XZ( Obj& ob){

		double s = 100; //skala

        for ( int i = 1; i < ob.face_size(); ++i){
			printl( (ob.get_v(i,1).a + abs(ob.min.a))*s , (ob.get_v(i,1).c + abs(ob.min.c))*s , (ob.get_v(i,2).a + abs(ob.min.a))*s , (ob.get_v(i,2).c + abs(ob.min.c))*s , 0, 0, 0);
        }	
    }
	void print_YZ( Obj& ob){

		double s = 100; //skala

        for ( int i = 1; i < ob.face_size(); ++i){
			printl( (ob.get_v(i,1).b + abs(ob.min.b))*s , (ob.get_v(i,1).c + abs(ob.min.c))*s , (ob.get_v(i,2).b + abs(ob.min.b))*s , (ob.get_v(i,2).c + abs(ob.min.c))*s , 0, 0, 0);
        }	
    }
	
	friend std::ostream& operator<<(std::ostream& os, const BMP& bmp);
};

}

#endif
