#include <iostream>
#include <fstream>
#include <vector>


class point{ //vertex is a point

	double a,b,c;

public:

	point(double aa, double bb, double cc): a(aa), b(bb), c(cc){}

	point(double* tab): a(tab[0]), b(tab[1]), c(tab[2]){}

};




class triangle{

	int v1, v2, v3;
	point** v_list;

public:

	
	triangle(int p1, int p2, int p3): v1(p1), v2(p2), v3(p3) { v_list = new point*[3]; }


	triangle(int* tab):v1(tab[0]),v2(tab[1]),v3(tab[2]) { v_list = new point*[3]; }


	~triangle() { delete [] v_list; }



	point** get_points( std::vector<point> & vertex ) {
		
		// zaleznie od numeracji. gdy pierwszy el = 0, to n=0, gdy pierwszy el=1, n =1
		int n = 1;

		v_list[0] = &(vertex[v1-n]);
		v_list[1] = &(vertex[v2-n]);
		v_list[2] = &(vertex[v3-n]);
	
		return v_list;
	}

};



struct file_error{};





class Obj{

	std::fstream file;
	
	std::vector <point> vertex;  // czy moze array!!???? zeby adresy mi sie nie zmieni³y
	std::vector <triangle> face;
	

public:

	Obj(std::string);
	~Obj();

	void open(std::string file_name);

	void check_error();

	void get_points();

	void get_triangles();

	point** operator[] (int i);

	void write();

	void clear_file();
};

