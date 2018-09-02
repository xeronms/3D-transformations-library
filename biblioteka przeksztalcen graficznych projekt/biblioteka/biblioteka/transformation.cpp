#include "transformation.h"




// TRANSFORMATION ==========================================================================

Transformation::~Transformation(){}



Matrix Transformation::get_matrix() const {

	return *matrix;
}



Matrix Transformation::get_inv_matrix() const {

	return *inverse;
}



Complex_Transformation Transformation::operator+ ( const Transformation& t ) const {

	// dodawanie dwoch transformacji tworzy complex_trans. ale gdy dodajemy complex_trans do czegos innego to korzystamy z wirtualnej wersji w klasie complex_trans
	
	return Complex_Transformation(*this, t);
}



/*

Transformation Transformation::operator- (){

	Transformation tmp;

	tmp.matrix = this->inverse;

	tmp.inverse = this->matrix;


	return tmp;
}




Complex_Transformation Transformation::operator- ( Transformation& t ){

	return *this + (-t);
}
*/



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



const Translation Translation::operator- (){

	Translation tmp;

	*tmp.matrix = *this->inverse;

	*tmp.inverse = *this->matrix;


	return tmp;
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



const Scaling Scaling::operator- (){

	Scaling tmp;

	*tmp.matrix = *this->inverse;

	*tmp.inverse = *this->matrix;


	return tmp;
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



const Rotation Rotation::operator- (){

	Rotation tmp;

	*tmp.matrix = *this->inverse;

	*tmp.inverse = *this->matrix;


	return tmp;
}