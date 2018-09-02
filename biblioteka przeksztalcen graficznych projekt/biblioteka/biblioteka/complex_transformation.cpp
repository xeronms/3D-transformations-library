#include "transformation.h"


// COMPLEX TRANSFORMATION ==========================================================================



Complex_Transformation::Complex_Transformation(){}



Complex_Transformation::Complex_Transformation( const Transformation& t,  const Transformation& t2 ){

	// funkcja uzywana dla operator+
	
	transformations.push_back( &t );

	transformations.push_back( &t2 );
}



Complex_Transformation::Complex_Transformation( const Transformation& t ){

	// CT = T

	transformations.push_back( &t );

}



Complex_Transformation::Complex_Transformation( const Complex_Transformation& t ){

	//	 CT = T1 + T2

	transformations = t.transformations; // for i in transformations ??
}



Complex_Transformation Complex_Transformation::operator+ ( const Transformation& t ) const { 

	// CT[T1,T2] + T3 = CT[T1,T2,T3]

	Complex_Transformation ct ( *this );

	ct.transformations.push_back( &t );

	return ct;
}




void Complex_Transformation::operator+= ( const Transformation& t ){ 

	// 

	transformations.push_back( &t );


}


/*
Complex_Transformation Complex_Transformation::operator+ ( const Complex_Transformation& t ){ 

	// CT[T1,T2] + T3 = CT[T1,T2,T3]

	transformations.push_back( t );

	return *this;
}
*/


const Transformation& Complex_Transformation::operator= ( const Complex_Transformation& t ){
	
	transformations = t.transformations;

	return *this;
}



const Transformation& Complex_Transformation::operator[] ( int i ) const {

	return *(transformations)[i];

}


/*
Transformation* Complex_Transformation::operator[] ( int i ) {

	return *(transformations)[i];

}
*/

/*
const Transformation& Complex_Transformation::operator>> ( Obj& obj) {

	obj.transform( get_matrix() );

	return *this;
}*/



Matrix Complex_Transformation::get_matrix() const {

	Matrix m(4,4);

	m.translation_init(0,0,0);

	for ( size_t i = 0; i < transformations.size(); ++i ){
	
		m = m * (*transformations[i]).get_matrix();
		m.rysuj();
	}

	return m;
}



/*
void Complex_Transformation::push ( const Transformation& t ){

	transformations.push_back( t );

}*/