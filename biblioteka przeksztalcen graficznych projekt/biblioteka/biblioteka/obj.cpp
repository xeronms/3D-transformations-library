#include "obj.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


Obj::Obj(std::string file_name) : name(file_name) {
	open(file_name);
	clear_file();
}


Obj::~Obj(){

	if ( file.is_open() )
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
					
                                        tmp[i++] = std::stod(number.c_str());
					
				}

                                //std::cout << tmp[0] << tmp[1] << tmp[2]<< std::endl;
				// dodajemy nowy punkt do wektora punktow
				
				if (tmp[0] < min.a) min.a = tmp[0];
				if (tmp[1] < min.b) min.b = tmp[1];
				if (tmp[2] < min.c) min.c = tmp[2];
				

				vertex.push_back( point ( tmp ) );
					
			}
		}
	}

        min.a = abs(min.a) + 1;
        min.b = abs(min.b) + 1;
        min.c = abs(min.c) + 1;
        //std::cout << min.a << min.b << min.c << std::endl;

	clear_file();
}



void Obj::load_triangles(){

        check_error();

        char c;
        std::string data;


        clear_file();

        while ( file.get(c) ){
                if ( c == 'f' ){
                        file.get(c);
                        if (  c == ' '){ // upewnienie sie, drugi znak linijki

                                getline( file, data);

                                std::istringstream idata(data);
                                std::string number;
                                int tmp[3];
                                int i = 0;


                                while(i < 3){

                                        idata >> number;
                                        //std::cout << number ;

                                        tmp [ i++ ] = atoi( number.c_str() );

                                }

                                face.push_back( triangle ( tmp ) );

                        }

                }
        }
}



point& Obj::get_v (int i , int j, int n) {
	// n = 1 gdy mamy numeracje od 1
	return face[i-n].get_v(vertex, j);

}


/*				ERROR 

void Obj::transform ( const Transformation & T){

	T.get_transformation_matrix() * Matrix ( vertex[0] );



}
*/



void Obj::save_file () {

    std::ofstream fileout("fileout.obj"); //Temporary file
    if( ! fileout.good() ) throw file_error();

    std::string strTemp;
	std::cout.unsetf ( std::ios::floatfield );   
	std::cout.precision(15); // nie usuwa miejsc po przecinku
    

	for ( std::vector<point>::iterator it = vertex.begin(); it != vertex.end(); ++it ){
	
		fileout << "v " << (*it).a << " " << (*it).b << " " << (*it).c << "\n" ;
	}

	for ( std::vector<triangle>::iterator it = face.begin(); it != face.end(); ++it ){
	
		fileout << "f " << (*it).v1 << " " << (*it).v2 << " " << (*it).v3 << "\n" ;
	}

	file.close();

	fileout.close();

	remove( name.c_str() );

	rename( "fileout.obj", name.c_str() );

}