#include "bmp.h"
#include "Interpreter.h"
#include "Rysownik.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <cstring>

int main(int argc, char* argv[]) {

        const uint16_t imgWidth = 800;
        const uint16_t imgHeight = 600;

        JiMP2::BMP bmp(imgWidth, imgHeight);
        Interpreter I;

        for (int i=argc-1; i>0; --i){
            try{
                std::string sciezka = argv[i];
                I.interpretuj(sciezka,bmp);
            }
            catch (file_error) {printf("ERR\n");}
        }

        std::ofstream outfile("out.bmp", std::ofstream::binary);
        outfile << bmp;

        std::cout << "end." << std::endl;

        return 0;
}
