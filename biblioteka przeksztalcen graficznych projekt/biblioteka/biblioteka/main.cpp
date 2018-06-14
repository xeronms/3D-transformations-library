#include "obj.h"
#include "bmp.h"

int main(){


	try{

		Obj cube("diamond.obj");

		cube.load_points();
		cube.load_triangles();

		//std::cout << cube.get_v(5,2).c << std::endl;
		// za pomoc¹ dostêpu get_v probujemy przekezac to do bmp

        const uint16_t imgWidth = 800;
	const uint16_t imgHeight = 600;

	JiMP2::BMP bmp(imgWidth, imgHeight);

	bmp.print_XY(cube);
	
	std::ofstream outfile("test.bmp", std::ofstream::binary);
	outfile << bmp;

	std::cout << "end." << std::endl;


        }

        catch (file_error){ printf("ERR\n");}



	return 0;
}
