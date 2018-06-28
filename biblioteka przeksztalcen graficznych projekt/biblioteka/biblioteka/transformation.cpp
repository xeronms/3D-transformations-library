#include "transformation.h"




Transformation::~Transformation(){

	delete matrix;
}

Matrix Transformation::get_matrix() const {

	return *matrix;
}

const Transformation& Transformation::operator>> ( Obj& obj) const {

	obj.transform( *matrix );

	return *this;
}




Translation::Translation( double dx, double dy, double dz ) {

	matrix = new Matrix( 4, 4);

	matrix->translation_init( dx, dy, dz );

}




Complex_Transformation::Complex_Transformation( const Transformation& t ){

	matrix = new Matrix( t.get_matrix() );

}

const Transformation& Complex_Transformation::operator=( const Transformation& t ){

	*matrix = t.get_matrix();

	return *this;
}