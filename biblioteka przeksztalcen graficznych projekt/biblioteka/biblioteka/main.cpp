#include "matrix.h"
#include "transformation.h"
#include "obj.h"



int main(){

	

	try{

		Obj object("ground.obj");

		object.load_points();
		object.load_triangles();

		Translation T(0,30,3);

		Complex_Transformation CT = T;

		Scaling S( 1, 4, 1);

		CT = S;

		CT >> object;

		object.save_file();
		
        }
		catch (error){ printf("ERRrrrr\n");}
        catch (file_error){ printf("ERR\n");}
	return 0;
}
