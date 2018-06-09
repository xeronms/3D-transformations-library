#include "obj.h"


int main(){


	try{

		Obj cube("diamond.obj");

		cube.load_points();
		cube.load_triangles();

		std::cout << cube.get_v(5,2).c << std::endl;


	}

	catch (file_error){ printf("ERR\n");}



	return 0;
}