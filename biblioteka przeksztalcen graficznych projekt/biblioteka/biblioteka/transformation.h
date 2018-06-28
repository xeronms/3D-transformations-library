#ifndef TRANS_H
#define TRANS_H

#include "matrix.h"
#include "obj.h"

#include <vector>
#include <stack>


class Complex_Transformation;


class Transformation{

protected:

	Matrix *matrix;

public:

	Transformation(){ matrix = new Matrix (4,4);}

	virtual ~Transformation();

	Matrix get_matrix() const ;

	virtual const Complex_Transformation operator+ ( const Transformation& );

	const Transformation operator- ( const Transformation& );

	const Transformation& operator>> ( Obj& obj) const ;

};


// ==========================================================================================================================


class Translation : public Transformation{

public:

	Translation( double dx, double dy, double dz );

	~Translation(){ delete matrix;}
};


// ==========================================================================================================================


class Scaling : public Transformation{

public:

	Scaling( double sx, double sy, double sz );

	~Scaling(){ delete matrix;}
};


// ==========================================================================================================================


class Rotation : public Transformation{

};


// ==========================================================================================================================


class Complex_Transformation : public Transformation{

	std::vector< Transformation > transformations;

public:
	Complex_Transformation(){ matrix = new Matrix (4,4);}

	~Complex_Transformation(){ delete matrix;}

	Complex_Transformation( const Matrix&, const Transformation& t,  const Transformation& t2 );

	Complex_Transformation( const Complex_Transformation& );

	virtual const Complex_Transformation operator+ ( const Transformation& );

	const Transformation& operator= ( const Complex_Transformation& );

	void push ( const Transformation& );

};


#endif