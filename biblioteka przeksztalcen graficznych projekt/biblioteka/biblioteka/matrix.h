//#ifndef _MATRIX_H_
//#define _MATRIX_H_

#ifndef MAT_H
#define MAT_H


#include <string>
#include "resources.h"

// changed index from r*i+j to that:
#define INDEX c*i+j

typedef unsigned int uint;



class error{
protected:
	error(){	printf("ERR\n");}
};

class size_err : public error{};

class zero_err : public error{};



class Matrix{


	double *data;

	unsigned int r, c;


public:


	Matrix(unsigned int r_,unsigned int c_):r(r_),c(c_){
		data = new double [r_*c_];
}

	// Matrix for 3D point
	Matrix ( const point& v );
	

	Matrix(const Matrix &m):r(m.r),c(m.c){
		data = new double [r*c];
		memcpy(data, m.data, r*c*sizeof(double));
}


	~Matrix(){
		delete [] data;
}


	Matrix &operator=(const Matrix &m){
		r = m.r; c = m.c;
		delete [] data;
		data = new double [r*c];
		memcpy(data, m.data, r*c*sizeof(double));
		return *this;
}


	void init(double);

	// for 3D operations data initialization:
	void translation_init(  double dx, double dy, double dz );

	void scaling_init( double sx, double sy, double sz );

	void rotation_init();

	void rysuj() const;

	double operator()(uint a, uint b) const;

	Matrix operator()(uint a, uint b, double val);

	Matrix operator+(const Matrix&) const;

	Matrix operator-(const Matrix&) const;

	Matrix operator-() const;

	Matrix operator*(double) const;

	Matrix operator*(const Matrix&) const;

	Matrix transpozycja();

	double wyznacznik() const;

	bool operator==(const Matrix&) const;

	bool operator!=(const Matrix&) const;

};

Matrix operator*(double, const Matrix&);


#endif