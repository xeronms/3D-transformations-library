#ifndef R_H
#define R_H

#include <vector>


class Transformation;

class Obj;

enum axis { x , y , z };

struct point{ //vertex is a point

	double a,b,c;

	point(double aa=0, double bb=0, double cc=0): a(aa), b(bb), c(cc){}

	point(double* tab): a(tab[0]), b(tab[1]), c(tab[2]){}

};



struct triangle{

	int v1, v2, v3;

	
	triangle(int p1, int p2, int p3): v1(p1), v2(p2), v3(p3) {}


	triangle(int* tab):v1(tab[0]),v2(tab[1]),v3(tab[2]) {}



	point& get_v( std::vector<point> & vertex , int i, int n = 1 ) {
		// zaleznie od numeracji. gdy pierwszy el = 0, to n=0, gdy pierwszy el=1, n =1
		
		int tab[3] = {v1,v2,v3};
	
		return vertex[ tab[i] - n ];
	}

};

#endif