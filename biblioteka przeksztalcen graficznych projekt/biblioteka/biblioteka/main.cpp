#include "obj.h"
#include "matrix.h"
#include "transformation.h"

int main(){

	

	try{

		Obj object("ground.obj");

		object.load_points();
		object.load_triangles();

		//object.save_file();

		
        }

        catch (file_error){ printf("ERR\n");}

	return 0;
}
