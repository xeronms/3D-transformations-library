
#ifndef _RYS_
#define _RYS_
#include "bmp.h"

class Rysownik{
public:
    virtual void printl(JiMP2::BMP& bmp, uint16_t  x1, uint16_t y1, uint16_t x2, uint16_t y2, unsigned char r, unsigned char g, unsigned char b) const =0;
    virtual void circleEmpty(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b) const =0;
    virtual void circleFilled(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b) const =0;
	virtual void archEmpty(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, uint16_t beg, uint16_t end, unsigned char r, unsigned char g, unsigned char b)const =0;
	virtual void archFilled(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, uint16_t beg, uint16_t end, unsigned char r, unsigned char g, unsigned char b)const =0;

};

class RysownikImplementacja : public Rysownik{
public:
    virtual void printl(JiMP2::BMP& bmp, uint16_t  x1, uint16_t y1, uint16_t x2, uint16_t y2, unsigned char r, unsigned char g, unsigned char b) const;
    virtual void circleEmpty(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b) const;
    virtual void circleFilled(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, unsigned char r, unsigned char g, unsigned char b) const;
	virtual void archEmpty(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, uint16_t beg, uint16_t end, unsigned char r, unsigned char g, unsigned char b) const;
	virtual void archFilled(JiMP2::BMP& bmp, uint16_t x0, uint16_t y0, uint16_t rad, uint16_t beg, uint16_t end, unsigned char r, unsigned char g, unsigned char b) const;
};

#endif
