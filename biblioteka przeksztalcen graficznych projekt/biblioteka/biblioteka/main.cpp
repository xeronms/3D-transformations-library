#include "matrix.h"
#include "transformation.h"
#include "obj.h"



int main(){

	

	try{

		Obj object("ground.obj");

		object.load_points();
		object.load_triangles();

		Translation T(1,5,3);

		//Transformation T;

		//T.translation(15.1, 1.1, 1.1).rysuj();

		//object.transform( T );

		//object.save_file();

		
        }
		catch (error){ printf("ERRrrrr\n");}
        catch (file_error){ printf("ERR\n");}
	return 0;
}
