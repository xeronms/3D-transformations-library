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


Rotation::Rotation( axis os, double angle, double dx, double dy, double dz ){

	matrix =
 Matrix( 4, 4);

	if ( dx || dy || dz ) // jesli os obrotu inna niz 0 0 0
	{}


	matrix.rotation_init( os, angle );
}





// COMP TRANSL ===================================================================================



Complex_Transformation::Complex_Transformation(){

	matrix = Matrix(4,4);
}


Complex_Transformation::Complex_Transformation( const Transformation& t,  const Transformation& t2 ){

	matrix = Matrix ( 4,4);

	transformations.push_back( &t );

	transformations.push_back( &t2 );
}



Complex_Transformation::Complex_Transformation( const Complex_Transformation& t ){

	matrix = Matrix( t.get_matrix() );

	transformations = t.transformations;
}


Complex_Transformation Complex_Transformation::operator+ ( const Transformation& t ){ 

	// CT[T1,T2] + T3 = CT[T1,T2,T3]

	transformations.push_back( &t );

	return *this;
}


const Transformation& Complex_Transformation::operator= ( const Complex_Transformation& t ){
	
	matrix = Matrix( t.get_matrix() );

	transformations = t.transformations;

	return *this;
}
/*
void  Complex_Transformation::operator>> ( Obj& obj) const {

	*matrix = (*transformations)[0].get_matrix();

	for ( int i = 1 ; i < transformations->size(); i++ ){
	
		*matrix = *matrix * (*transformations)[i].get_matrix();
	}

	obj.transform( *matrix );

}
*/

const Transformation& Complex_Transformation::operator[] ( int i ) const {

	return *(transformations)[i];

}


/*
void Complex_Transformation::push ( const Transformation& t ){

	transformations.push_back( t );

}*/