#ifndef TRANS_H
#define TRANS_H

#include "matrix.h"
//#include "obj.h"

#include <vector>
#include <stack>



class Transformation{

	//Matrix transformation_matrix;

	std::stack<Matrix> matrix_stack; // std::stack?      

	//std::vector<point> vertexes;



public:

	Transformation();

	virtual ~Transformation();

	Matrix translation( double dx, double dy, double dz ); // dostajemy macierz przeksztalcen, dodajemy ja na stos i pozniej mnozymy przez nastepne przeksztalcenia. 

	Matrix scaling( double sx, double sy, double sz );
	 
	Matrix rotation();

	//std::vector<point> transform( const std::vector<point> & ) const ; // daje koncowy efekt, mozemy tez zrobic funkcje w obj ktora przyjmuje za argument klase Transformation
	
	// transformation() function in obj class

	const Matrix& get_transformation_matrix() const ;

};





#endif