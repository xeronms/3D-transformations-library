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

	Transformation( const Transformation& t);

	virtual ~Transformation();

	Matrix get_matrix() const ;

	virtual Complex_Transformation operator+ ( const Transformation& );

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


class Complex_Transformation : public Transformation{

protected:

	std::vector< Transformation > transformations;

public:
	Complex_Transformation(){ matrix = new Matrix (4,4);}

	~Complex_Transformation(){ delete matrix;}

	Complex_Transformation( const Matrix&, const Transformation& t,  const Transformation& t2 );

	Complex_Transformation( const Complex_Transformation& );

	virtual Complex_Transformation operator+ ( const Transformation& );

	const Transformation& operator= ( const Complex_Transformation& );

	void push ( const Transformation& );

	void prnt(){
	
		for (int i =0;i<transformations.size();++i){
		
			transformations[i].get_matrix().rysuj();
		}
	}

};


// ==========================================================================================================================


class Rotation : public Complex_Transformation{

public:

	Rotation( axis os, double angle, double dx = 0, double dy = 0, double dz = 0);

	~Rotation(){ delete matrix;}
};



#endif