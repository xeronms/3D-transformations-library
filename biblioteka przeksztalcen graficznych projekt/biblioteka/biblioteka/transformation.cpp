#include "transformation.h"





Translation::Translation( double dx, double dy, double dz ) {

	matrix = new Matrix( 4, 4);

	matrix->translation_init( dx, dy, dz );

}

Translation::~Translation(){

	delete matrix;
}



Complex_Transformation::Complex_Transformation(){

	matrix = new Matrix( 4, 4);
}
