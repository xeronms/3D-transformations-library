#include "matrix.h"
#include "transformation.h"
#include "obj.h"



int main(){

	

	try{

		Obj object("ground.obj");

		object.load_points();
		object.load_triangles();

		Translation T(0,30,3);

		Scaling S( 0.8, 0.8, 0.8);

		Translation T2(0,-20,-1);
		
		Complex_Transformation CT ( S + T );
		//CT.prnt();

		CT = CT + T2;


		CT.get_matrix().rysuj();

		CT >> object;

		object.save_file();
		
        }
		catch (error){ printf("ERRrrrr\n");}
        catch (file_error){ printf("ERR\n");}
	return 0;
}
