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

	point *v1, *v2, *v3;

public:

	triangle(point * p1, point * p2, point * p3): v1(p1), v2(p2), v3(p3){}

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

	void write();

	void clear_file();
};

