#include "bmp.h"
#include "Rysownik.h"
#include "Interpreter.h"
#include <fstream>
#include <string>
#include <sstream>

void Interpreter::interpretuj(std::string& sciezka,JiMP2::BMP& bmp){
    std::ifstream plik;
    plik.open(sciezka);
    if (!plik.good()) throw file_error();
    std::string data;
    std::string::size_type sz;
    int i;
    char c, c2;
	int obecna_linia = 0;

    while (plik.get(c)){
		plik.get(c2);
        getline(plik, data);
		++obecna_linia;

        switch (c) {


        case 'l':
        case 'L':

			if ( Lcommand( data ) == false ) throw  line_error( obecna_linia );
            //std::cout << x1 << y1 << x2 <<y2 << (int)r <<std::endl<< std::endl;
            rys.printl(bmp,(uint16_t) x1,(uint16_t) y1,(uint16_t) x2,(uint16_t) y2, r,g,b);

            ++obecna_linia;
			
			break;


        case 'c':
        case 'C':

			if ( Ccommand( data ) == false ) throw  line_error( obecna_linia );
            
			rys.circleEmpty(bmp,(uint16_t) x1,(uint16_t) y1,(uint16_t) rad,r,g,b);
            
			++obecna_linia;
			
			break;


        case 'd':
        case 'D':

            if ( Dcommand( data ) == false ) throw  line_error( obecna_linia );
            
			rys.circleFilled(bmp,(uint16_t) x1,(uint16_t) y1,(uint16_t) rad,r,g,b);
            
			++obecna_linia;
			
            break;

			
		case 'a':
        case 'A':

            if ( Dcommand( data ) == false ) throw  line_error( obecna_linia );
            
			rys.archEmpty(bmp,(uint16_t) x1,(uint16_t) y1,(uint16_t) rad,r,g,b);
            
			++obecna_linia;
			
            break;

			
		case 's':
        case 'S':

            if ( Dcommand( data ) == false ) throw  line_error( obecna_linia );
            
			rys.archFilled(bmp,(uint16_t) x1,(uint16_t) y1,(uint16_t) rad,r,g,b);
            
			++obecna_linia;
			
            break;


        default:

            break;

        }
        ++i;
    }

    plik.close();
}


bool Interpreter::Lcommand(std::string& data){

	double xx1, xx2, yy1, yy2;
	unsigned int rr, gg, bb;
	std::istringstream iss(data);

	iss>>xx1>>yy1>>xx2>>yy2>>rr>>gg>>bb;
	std::cout << xx1<<yy1<<xx2<<yy2<<rr<<gg<<bb <<std::endl<< std::endl;
	if ( rr > 255 || gg > 255 || bb > 255 ) return false;

	x1 = xx1;
	y1 = yy1;
	x2 = xx2;
	y2 = yy2;
	r = rr;
	g = gg;
	b = bb;

	return true;
}


bool Interpreter::Ccommand(std::string& data){

	unsigned int rr, gg, bb;
	std::istringstream iss(data);

	iss>>x1>>y1>>rad>>rr>>gg>>bb;

	if ( rr > 255 || gg > 255 || bb > 255 ) return false;

	r = rr;
	g = gg;
	b = bb;

	return true;
}


bool Interpreter::Dcommand(std::string& data){

	unsigned int rr, gg, bb;
	std::istringstream iss(data);

	iss>>x1>>y1>>rad>>rr>>gg>>bb;

	if ( rr > 255 || gg > 255 || bb > 255 ) return false;

	r = rr;
	g = gg;
	b = bb;

	return true;
}


bool Interpreter::Acommand(std::string& data){

	unsigned int rr, gg, bb;
	std::istringstream iss(data);

	iss>>x1>>y1>>rad>>beg>>end>>rr>>gg>>bb;

	if ( rr > 255 || gg > 255 || bb > 255 ) return false;

	r = rr;
	g = gg;
	b = bb;

	return true;
}


bool Interpreter::Scommand(std::string& data){

	unsigned int rr, gg, bb;
	std::istringstream iss(data);

	iss>>x1>>y1>>rad>>beg>>end>>rr>>gg>>bb;

	if ( rr > 255 || gg > 255 || bb > 255 ) return false;

	r = rr;
	g = gg;
	b = bb;

	return true;
}