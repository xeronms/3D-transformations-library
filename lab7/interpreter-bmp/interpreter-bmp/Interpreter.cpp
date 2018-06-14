#include "bmp.h"
#include "Rysownik.h"
#include "Interpreter.h"
#include <fstream>
#include <string>

void Interpreter::interpretuj(std::string& sciezka,JiMP2::BMP& bmp){
    std::ifstream plik;
    plik.open(sciezka);
    if (!plik.good()) throw file_error();
    std::string data;
    std::string::size_type sz;
    int i;
    char c;

    while (plik.get(c)){
        getline(plik, data);
        switch (c) {
        case 'l':
        case 'L':
            x1=std::stod( data, &sz );
            y1=std::stod( data.substr(sz) );
            x2=std::stod( data.substr(sz) );
            y2=std::stod( data.substr(sz) );
            r=std::stod( data.substr(sz) );
            g=std::stod( data.substr(sz) );
            b=std::stod( data.substr(sz) );
            //std::cout << x1 << y1 << x2 <<y2 << (int)r <<std::endl<< std::endl;
            rys.printl(bmp,(uint16_t) x1,(uint16_t) y1,(uint16_t) x2,(uint16_t) y2, r,g,b);
            break;
        case 'c':
        case 'C':
            x1=std::stod( data, &sz );
            y1=std::stod( data.substr(sz) );
            rad=std::stod( data.substr(sz) );
            r=std::stod( data.substr(sz) );
            g=std::stod( data.substr(sz) );
            b=std::stod( data.substr(sz) );
            rys.circleEmpty(bmp,(uint16_t) x1,(uint16_t) y1,(uint16_t) rad,r,g,b);
            break;
        case 'd':
        case 'D':
            x1=std::stod( data, &sz );
            y1=std::stod( data.substr(sz) );
            rad=std::stod( data.substr(sz) );
            r=std::stod( data.substr(sz) );
            g=std::stod( data.substr(sz) );
            b=std::stod( data.substr(sz) );
            //std::cout << x1 << y1 << rad << (int)r <<std::endl<< std::endl;
            rys.circleFilled(bmp,(uint16_t) x1,(uint16_t) y1,(uint16_t) rad,r,g,b);
            break;
        default:
            break;
        }
        ++i;
    }

    plik.close();
}
