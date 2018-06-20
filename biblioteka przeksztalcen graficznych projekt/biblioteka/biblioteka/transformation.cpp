#include "transformation.h"





const Matrix& Transformation::translation( double dx, double dy, double dz ) {
	 

	matrix_stack.emplace( Matrix( 4, 4) );

	matrix_stack.top().translation_init( dx, dy, dz );

	return matrix_stack.top();
}



const Matrix& Transformation::get_transformation_matrix() const {

	return matrix_stack.top();

}
