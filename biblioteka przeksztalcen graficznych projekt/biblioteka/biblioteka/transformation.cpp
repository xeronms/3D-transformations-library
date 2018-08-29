#include "transformation.h"




// TRANSFORMATION ==========================================================================


Transformation::Transformation( const Transformation& t){
		matrix = Matrix( t.get_matrix() );
}



Matrix Transformation::get_matrix() const {

	return matrix;
}



Complex_Transformation Transformation::operator+ ( const Transformation& t ){

	// dodawanie dwoch transformacji tworzy complex_trans. ale gdy dodajemy complex_trans do czegos innego to korzystamy z wirtualnej wersji w klasie complex_trans
	
	return Complex_Transformation(*this, t);
}



Transformation Transformation::operator- (){

	matrix = - matrix;

	return *this;
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

}




// SCALING =========================================================================================


Scaling::Scaling( double sx, double sy, double sz ){

	matrix = Matrix( 4, 4);

	matrix.scaling_init( sx, sy, sz );

}




// ROTATION =======================================================================================


Rotation::Rotation( axis os, double angle ){

	matrix = Matrix( 4, 4);
	
	matrix.rotation_init( os,  (angle*3.14159265)/180 );
}



