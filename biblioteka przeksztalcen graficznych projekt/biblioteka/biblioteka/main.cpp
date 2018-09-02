#include "matrix.h"
#include "transformation.h"
#include "obj.h"



int main(){

	

	try{

		Obj object("cow.obj");

		object.load_points();
		object.load_triangles();

		Translation T(0,5,0);

		Scaling S( 0.8, 0.8, 0.8);

		Translation T2(0,-0.20,-1);
		
		Scaling S2(10,10,10);

		Scaling S3 (0.5);

		Rotation R(z,-180); // sin 360 != 0

		Rotation R2(y,90);

		//Complex_Transformation CT ( S + T );

		//CT = CT + S2 - S -T;

		Complex_Transformation CT2 = T2 + S2 + T;

		Complex_Transformation CT = R + T + S3 ; // - odejmuje macierze a nie oblicza wyznacznik
				
		CT2 += CT ; // ???????????????

		//CT = CT2;

		//CT = CT + CT2;


		(S).get_matrix().rysuj();

		(S) >> object;

		object.save_file();
		
        }
		catch (error){ printf("ERRrrrr\n");}
        catch (file_error){ printf("ERR\n");}

	return 0;
}
