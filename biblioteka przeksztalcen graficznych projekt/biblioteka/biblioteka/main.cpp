#include "matrix.h"
#include "transformation.h"
#include "obj.h"



int main(){

	

	try{

		Obj object("ground.obj");

		object.load_points();
		object.load_triangles();

		Translation T(0,29,-28);

		Scaling S( 0.8, 0.8, 0.8);

		Translation T2(0,-0.20,-1);
		
		Scaling S2(10,10,10);

		Complex_Transformation CT ( S + T );

		//CT = CT + S2;


		CT >> object;
		

		CT.get_matrix().rysuj();

		//T >> object;

		object.save_file();
		
        }
		catch (error){ printf("ERRrrrr\n");}
        catch (file_error){ printf("ERR\n");}

	return 0;
}
