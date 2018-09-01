#include "transformation.h"




// TRANSFORMATION ==========================================================================


Transformation::Transformation( const Transformation& t){

		matrix = Matrix( t.matrix );

		inverse = Matrix( t.inverse );

}



Matrix Transformation::get_matrix() const {

	return matrix;
}



Complex_Transformation Transformation::operator+ ( const Transformation& t ){

	// dodawanie dwoch transformacji tworzy complex_trans. ale gdy dodajemy complex_trans do czegos innego to korzystamy z wirtualnej wersji w klasie complex_trans
	
	return Complex_Transformation(*this, t);
}



Transformation Transformation::operator- (){

	Transformation tmp;

	tmp.matrix = this->inverse;

	tmp.inverse = this->matrix;


	return tmp;
}




Complex_Transformation Transformation::operator- ( Transformation& t ){

	return *this + (-t);
}




const Transformation& Transformation::operator>> ( Obj& obj) const {

	obj.transform( matrix );

	return *this;
}




// TRANSLATION ====================================================================================


Translation::Translation( double dx, double dy, double dz ) {

	matrix =  Matrix( 4, 4);

	matrix.translation_init( dx, dy, dz );
	
	inverse =  Matrix( 4, 4);

	inverse.translation_init( -dx, -dy, -dz );

}




// SCALING =========================================================================================


Scaling::Scaling( double sx, double sy, double sz ){

	// if ( sx , sy, sz == 0) thorw ...

	matrix = Matrix( 4, 4);

	matrix.scaling_init( sx, sy, sz );

	inverse =  Matrix( 4, 4);

	inverse.scaling_init( 1/sx, 1/sy, 1/sz );

}




// ROTATION =======================================================================================


Rotation::Rotation( axis os, double angle ){

	matrix = Matrix( 4, 4);
	
	matrix.rotation_init( os,  (angle*3.14159265)/180 );

	inverse =  Matrix( 4, 4);

	inverse.rotation_init( os,  -(angle*3.14159265)/180 );

}



