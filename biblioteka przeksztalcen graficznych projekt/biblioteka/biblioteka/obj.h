#ifndef OBJ_H
#define OBJ_H

#include <iostream>
#include <fstream>
#include <vector>



class point{ //vertex is a point
public:
	double a,b,c;



	point(double aa=0, double bb=0, double cc=0): a(aa), b(bb), c(cc){}

	point(double* tab): a(tab[0]), b(tab[1]), c(tab[2]){}

};




class triangle{

	int v1, v2, v3;

public:

	
	triangle(int p1, int p2, int p3): v1(p1), v2(p2), v3(p3) {}


	triangle(int* tab):v1(tab[0]),v2(tab[1]),v3(tab[2]) {}



	point& get_v( std::vector<point> & vertex , int i, int n = 1 ) {
		// zaleznie od numeracji. gdy pierwszy el = 0, to n=0, gdy pierwszy el=1, n =1
		
		int tab[3] = {v1,v2,v3};
	
		return vertex[ tab[i] - n ];
	}

};



struct file_error{};





class Obj{

	std::fstream file;
	
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


	 /*std::vector<triangle>& get_faces(){
		 return face;
	}

	  std::vector<point>& get_faces(){
		 return face;
	}*/
};



#endif
