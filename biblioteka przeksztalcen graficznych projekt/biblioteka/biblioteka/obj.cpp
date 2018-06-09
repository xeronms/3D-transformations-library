#include "obj.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
//#include "cube.obj"


Obj::Obj(std::string file_name){
	open(file_name);
	clear_file();
}


Obj::~Obj(){
	file.close();
}


void Obj::open(std::string file_name){
	file.open ( file_name, std::ios::in );
	check_error();
}


void Obj::clear_file(){
	file.clear();
	file.seekg( 0 );
}


void Obj::check_error(){
	if ( !file.good() ) throw file_error();
}




void Obj::get_points(){

	check_error();

	char c;
	std::string data;

	
	clear_file();
	

	while ( file.get(c) ){
		
		if (c=='v' ){ // pierwszy znak linijki

			file.get(c) ;

			if (  c == ' '){ // upewnienie sie, drugi znak linijki

				getline( file, data);

				std::istringstream idata(data);
				std::string number;
				double tmp[3];
				int i = 0;


				while(i < 3){

					idata >> number;
					
					tmp[i++] = atoi(number.c_str());

				}

				std::cout << tmp[0] << tmp[1] << tmp[2]<< std::endl;
				// dodajemy nowy punkt do wektora punktow
				vertex.push_back( point ( tmp ) );
					
			}
		}
	}

	clear_file();
}



	
void Obj::get_triangles(){

	check_error();

	char c;
	std::string data;
	unsigned int i = 0, j=0;


	clear_file();

	while ( file.get(c) ){
		if ( c == 'f' ){
			file.get(c);
			if ( c == ' ' ){
				
				int tab[3];

				getline( file, data);
				j=0;
				i=0;
				while ( i<3 ){
					if ( data[j] == ' ' ){
						tab [ i++ ] = atoi( (data.c_str())+(++j) ); 
						//std::cout << tab[i-1] << std::endl;
					}

					++j;

				}

				face.push_back( triangle ( tab ) );

			}
		}
	}
}


