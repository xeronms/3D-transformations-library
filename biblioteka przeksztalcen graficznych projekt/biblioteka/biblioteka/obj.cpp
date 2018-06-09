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

	char c2;
	std::string data;

	
	clear_file();
	

	while ( file.get(c2) ){
		
		if (c2=='v' ){ // pierwszy znak linijki

			file.get(c2) ;

			if (  c2 == ' '){ // upewnienie sie, drugi znak linijki

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

	char c2;
	std::string data;
	//std::string::size_type sz;
	unsigned int i = 0, j=0;
	unsigned int index = 0;

	clear_file();

	while ( file.get(c2) ){
		if ( c2 == 'f' ){
			file.get(c2);
			if ( c2 == ' ' ){
				getline( file, data);
				j=0;
				i=0;
				while ( i<3 ){
					if ( data[j] == ' ' ){
						printf("%d\t",atoi( (data.c_str())+(++j) ));
						/**t[index].v1 = p[atoi( (data.c_str())+(j) ) - 1];
						*t[index].v2 = p[atoi( (data.c_str())+(j) ) - 1];  ????
						*t[index].v2 = p[atoi( (data.c_str())+(j) ) - 1];*/
						++i;
					}
					++j;
				}
				std::cout<<std::endl;
			}
			++index;
		}
	}
}


