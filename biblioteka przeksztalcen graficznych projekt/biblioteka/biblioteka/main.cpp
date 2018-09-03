#include "matrix.h"
#include "transformation.h"
#include "obj.h"



int main(){

	

	try{

		Obj object("cow.obj");

		object.load_points();
		object.load_triangles();

		Translation T(0,5,0);

		Translation T2(0,-0.20,-1);

		Translation T3(10,0,-5);

		Scaling S( 0.8, 0.8, 0.8);
		
		Scaling S2(10,10,10);

		Scaling S3 (0.5);

		Rotation R(z,-180);

		Rotation R2(y,90);


		Complex_Transformation CT2 = T2 + S2 + T;

		Complex_Transformation CT = R + R2 + CT2 + S3 + T3 + S;
				


		Translation a1 ( 100 );
		Translation a2 ( 0, 0, -50);
		Scaling b1 ( 0.5 );
		Scaling b2 ( 10, 10, 10);
		Rotation c1( z, 90);
		Rotation c2( x, 120);

		Complex_Transformation B = ( a2 + b2);

		Complex_Transformation A = a1 + b1  + B + c1;

		CT += A;

		CT += c2;

		//CT - B; ???

		Complex_Transformation C = T2 - B + CT + T ;

		C[1] = a2;

		C[1].get_matrix().rysuj();

		//C >> object;

		//object.save_file();
		
        }
		catch (error){ printf("ERRrrrr\n");}
        catch (file_error){ printf("ERR\n");}

	return 0;
}
