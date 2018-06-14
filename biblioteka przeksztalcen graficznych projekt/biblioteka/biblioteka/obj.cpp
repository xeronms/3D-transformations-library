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




void Obj::load_points(){

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
				
				if (tmp[0] < min.a) min.a = tmp[0];
				if (tmp[1] < min.b) min.b = tmp[1];
				if (tmp[2] < min.c) min.c = tmp[2];
				

				vertex.push_back( point ( tmp ) );
					
			}
		}
	}

	clear_file();
}



	
void Obj::load_triangles(){

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


point& Obj::get_v (int i , int j, int n) {
	// n = 1 gdy mamy numeracje od 1
	return face[i-n].get_v(vertex, j);

}


