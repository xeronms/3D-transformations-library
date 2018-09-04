#include "matrix.h"
#include "transformation.h"
#include "obj.h"



int main(){

	

	try{

		Obj object("cow.obj");

		object.load_points();
		object.load_triangles();


		Rotation r1 (x, 180);
		Rotation r2 (z, -90);
		Rotation r3 (z, 30);
		Rotation r4 (x, -120);

		Translation t1(2);
		Translation t2(-5,3,0);
		Translation t3(0,-2,-2);
		Translation t4(2, 6, 1);

		Scaling s1(1.2);
		Scaling s2(1, 1, 3);
		Scaling s3(1, 0.5, 1);

		

		//D(4) >> object;

		object.save_file();
		
        }
		catch (error){ printf("ERRrrrr\n");}
        catch (file_error){ printf("ERR\n");}

	return 0;
}



/* 
		Complex_Transformation A = t1;

		Complex_Transformation B = A + t2;

		Complex_Transformation C = B + t3 ;
		
		Complex_Transformation D = C + t4 ;

		D[0][0][0] = r2;
		
		D += - s2;
		Complex_Transformation E = -D;
*/