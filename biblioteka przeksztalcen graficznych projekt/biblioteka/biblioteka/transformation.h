#ifndef TRANS_H
#define TRANS_H

#include "matrix.h"
#include "obj.h"

#include <vector>
#include <stack>


class Transformation{

protected:

	Matrix *matrix;

public:

	Transformation(){ matrix = new Matrix (4,4);}

	~Transformation();

	Matrix get_matrix() const ;

	const Transformation operator+ ( const Transformation& );

	const Transformation operator- ( const Transformation& );

	const Transformation& operator>> ( Obj& obj) const ;

	

};



class Translation : public Transformation{

public:

	Translation( double dx, double dy, double dz );

};



class Scaling : public Transformation{

public:

	Scaling( double sx, double sy, double sz );
};


class Rotation : public Transformation{

};

class Complex_Transformation : public Transformation{

public:

	Complex_Transformation();

	Complex_Transformation( const Transformation& );

	//virtual ~Complex_Transformation();
	
	const Transformation& operator=( const Transformation& );


};


#endif