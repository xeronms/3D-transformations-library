#include "transformation.h"





Matrix Transformation::translation( double dx, double dy, double dz ) {

	Matrix A (4, 4);

	A.translation_init ( dx, dy, dz);

	matrix_stack.push( A );

	return A;
}



const Matrix& Transformation::get_transformation_matrix() const {

	return matrix_stack.top();

}
