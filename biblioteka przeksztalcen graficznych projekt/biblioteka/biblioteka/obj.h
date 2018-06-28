#ifndef _OBJ_H
#define _OBJ_H

#include "matrix.h"
#include <iostream>
#include <fstream>
#include <vector>


struct file_error{};



class Obj{

	std::fstream file;
	std::string name;
	

	std::vector <point> vertex;  // czy moze array!!???? zeby adresy mi sie nie zmieni³y
	std::vector <triangle> face;
	
	

public:
	point min;

	Obj(std::string);
	~Obj();

	void open(std::string file_name);

	void check_error();

	void load_points();

	void load_triangles();

	point& get_v (int i, int j, int n=1);

	void write();

	void clear_file();

	inline int face_size() const{
		return face.size();
	}

	// transformation:

	void transform ( const Matrix & M ) ;

	void save_file() ;


	 /*std::vector<triangle>& get_faces(){
		 return face;
	}

	  std::vector<point>& get_faces(){
		 return face;
	}*/
};



#endif
