#include "obj.h"


int main(){


	try{

		Obj cube("cube.obj");

		cube.get_points();
		cube.get_triangles();




	}

	catch (file_error){ printf("ERR\n");}



	return 0;
}