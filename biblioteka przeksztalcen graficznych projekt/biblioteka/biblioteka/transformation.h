#ifndef TRANS_H
#define TRANS_H

#include "matrix.h"
#include "obj.h"

#include <vector>
#include <stack>


class Complex_Transformation;



class Transformation{

protected:

	Matrix* matrix;

	Matrix* inverse;

public:

	Transformation(){}

	virtual ~Transformation() = 0;
	
	virtual Matrix get_matrix() const ;

	virtual Matrix get_inv_matrix() const ;

	virtual Complex_Transformation operator+ ( Transformation& ) ;

	virtual Complex_Transformation operator- ( Transformation& t );

	virtual Transformation& operator- ();

	virtual const Transformation& operator[] ( int i ) const {return *this;}

	virtual Transformation& operator[] ( int i ) {return *this;}

	const Transformation& operator>> ( Obj& obj) const ;

};



// ==========================================================================================================================



class Translation : public Transformation{

public:

	Translation( double dx = 0, double dy = 0, double dz = 0 );

	Translation( const Translation& t);

	~Translation(){delete matrix; delete inverse; }


};



// ==========================================================================================================================



class Scaling : public Transformation{

public:

	Scaling( double sx = 1, double sy = 1, double sz = 1 );

	Scaling( const Scaling& t);

	~Scaling(){delete matrix; delete inverse; }

};



// ==========================================================================================================================



class Rotation : public Transformation{

public:

	Rotation( axis os = x, double angle = 0, double x = 0, double y = 0, double z = 0 ) ;
	
	Rotation( const Rotation& t);
	
	~Rotation(){delete matrix; delete inverse; }

};



// ==========================================================================================================================



class Complex_Transformation : public Transformation{

protected:

	std::vector < Transformation* > transformations;

public:
	Complex_Transformation();

	Complex_Transformation( Transformation& t );

	Complex_Transformation( Transformation& t , Transformation& t2);

	Complex_Transformation( const Complex_Transformation& );



	virtual Complex_Transformation operator+ ( Transformation& ) const ;

	virtual Transformation& operator- ();

	void operator+= (  Transformation& );

	const Transformation& operator= ( const Complex_Transformation& );

	const Transformation& operator[] ( int i ) const;

	Transformation& operator[] ( int i );

	Complex_Transformation operator() ( int i ); // podaje transformacje do i-tego elementu
	
	virtual Matrix get_matrix() const ;

	virtual Matrix get_inv_matrix() const ;

};




#endif