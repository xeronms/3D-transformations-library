#include "transformation.h"




// TRANSFORMATION ==========================================================================

Transformation::~Transformation(){}



Matrix Transformation::get_matrix() const {

	return *matrix;
}



Matrix Transformation::get_inv_matrix() const {

	return *inverse;
}



Complex_Transformation Transformation::operator+ (  Transformation& t ) {

	// dodawanie dwoch transformacji tworzy complex_trans. ale gdy dodajemy complex_trans do czegos innego to korzystamy z wirtualnej wersji w klasie complex_trans
	
	return Complex_Transformation(*this, t);
}





Complex_Transformation Transformation::operator- ( Transformation& t ){

	return *this + (-t);
}




Transformation& Transformation::operator- (){

	Matrix tmp = *matrix;

	*matrix = *inverse;

	*inverse = tmp;


	return *this;
}





const Transformation& Transformation::operator>> ( Obj& obj) const {

	obj.transform( get_matrix() );

	return *this;
}




// TRANSLATION ====================================================================================



Translation::Translation( double dx, double dy, double dz ) {

	matrix =  new Matrix( 4, 4);

	matrix->translation_init( dx, dy, dz );
	
	inverse =  new Matrix( 4, 4);

	inverse->translation_init( -dx, -dy, -dz );

}



Translation::Translation( const Translation& t){

	matrix = new Matrix( t.get_matrix() );

	inverse = new Matrix( t.get_inv_matrix() );

}




// SCALING =========================================================================================



Scaling::Scaling( double sx, double sy, double sz ){

	// if ( sx , sy, sz == 0) thorw ...

	matrix = new Matrix( 4, 4);

	matrix->scaling_init( sx, sy, sz );

	inverse =  new Matrix( 4, 4);

	inverse->scaling_init( 1/sx, 1/sy, 1/sz );

}



Scaling::Scaling( const Scaling& t){

	matrix = new Matrix( t.get_matrix() );

	inverse = new Matrix( t.get_inv_matrix() );

}




// ROTATION =======================================================================================



Rotation::Rotation( axis os, double angle ){

	matrix = new Matrix( 4, 4);
	
	matrix->rotation_init( os,  (angle*3.14159265)/180 );

	inverse =  new Matrix( 4, 4);

	inverse->rotation_init( os,  -(angle*3.14159265)/180 );

}



Rotation::Rotation( const Rotation& t){

	matrix = new Matrix( t.get_matrix() );

	inverse = new Matrix( t.get_inv_matrix() );

}

