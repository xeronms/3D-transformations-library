#ifndef TRANS_H
#define TRANS_H

#include "matrix.h"
//#include "obj.h"

#include <vector>
#include <stack>


class Transformation{

protected:

	Matrix *matrix;

public:

	virtual ~Transformation() = 0;

	virtual const Transformation& operator+ ( const Transformation& ) const = 0;

	virtual const Transformation& operator- ( const Transformation& ) const = 0;

	virtual const Transformation& operator>> ( Transformation& ) const = 0;


};



class Translation : public Transformation{

public:

	Translation( double dx, double dy, double dz );

	~Translation();

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