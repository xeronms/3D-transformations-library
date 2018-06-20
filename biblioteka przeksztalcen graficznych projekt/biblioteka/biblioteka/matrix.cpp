#include "matrix.h"
#include <iostream>

using namespace std;



Matrix::Matrix ( const point& v ) : r(4), c(1) {

	data = new double [r*c];
	data [0] = v.a;
	data [1] = v.b;
	data [2] = v.c;
	data [3] = 1;

}


void Matrix::init(double a){

	for (uint i=0; i<r*c; ++i){

		data[i]=a;

	}
}


void Matrix::translation_init(  double dx, double dy, double dz ){

	if (r!=4 || c!=4) throw size_err();


	for (uint i=0; i<r; ++i){
	
		for (uint j=0; j<c; ++j){

			switch (INDEX)
			{
			case 3: // pozycja macierzy [1,4]

				data[INDEX] = dx;
				break;
	
			case 7: // [2,4]

				data[INDEX] = dy;
				break;

			case 11: // [3,4]

				data[INDEX] = dz;
				break;

			default:

				if ( i == j )
					data[INDEX] = 1;

				else
					data[INDEX] = 0;

				break;

			}
		}
	}
}


void Matrix::scaling_init( double sx, double sy, double sz ){
	
	if (r!=4 || c!=4) throw size_err();


	for (uint i=0; i<r; ++i){
	
		for (uint j=0; j<c; ++j){

			if ( i == j ){ // przek¹tna macierzy

				switch (INDEX)
				{
				case 0: // pozycja macierzy [1,1]

					data[INDEX] = sx;
					break;
	
				case 5: // [2,2]

					data[INDEX] = sy;
					break;

				case 10: // [3,3]

					data[INDEX] = sz;
					break;

				default: // [4,4]

					data[INDEX] = 1;
					break;
				}

			}

			else 
				data[INDEX] = 0;

		}
	}
}




void Matrix::rysuj() const{
	for (uint i=0; i<(r*c); ++i){
		std::cout << data[i] << "\t";
		if (!((i+1)%c)) std::cout << std::endl;
	}
	std::cout << std::endl;
}


double Matrix::operator()(uint i, uint j) const{ //returning element [i,j]
	return data[INDEX];
}


Matrix Matrix::operator()(uint i, uint j, double val){ //swaping [i,j] element data with val
	 data[INDEX] = val;
	 return *this;
}


Matrix Matrix::operator+(const Matrix& m) const{
	if (r!=m.r || c!=m.c) throw size_err();
	Matrix m2(r,c);

	for (uint i=0; i<r*c; ++i){
		m2.data[i] = m.data[i] + data[i];
	}
	return m2;
}


Matrix Matrix::operator-() const{
	return (*this)*(-1);
}


Matrix Matrix::operator-(const Matrix& m) const{
	return *this + (-m);

}


Matrix Matrix::operator*(double k) const{
	Matrix m(r,c);
	for (uint i=0; i<r*c; ++i){
		m.data[i] = data[i] * k; 
	}
	return m;
}


Matrix Matrix::operator*(const Matrix& m) const{
	if (c!=m.r) throw size_err();
	Matrix m2(r,m.c);
	for (uint i=0; i<r; ++i){
		for (uint j=0; j<m.c; ++j){
			m2.data[i*m.c+j] = 0;
			for (uint k=0; k<c; ++k){
				m2.data[i*m.c+j] += data[i*c+k]*m.data[m.c*k+j];
			}
		}
	}
	return m2;
}


Matrix operator*(double k, const Matrix& m){
	return m*k;
}


Matrix Matrix::transpozycja(){
	Matrix m(*this);
	for (uint i=0; i<r; ++i){
		for (uint j=0; j<c; ++j){
			data[INDEX] = m.data[j*r+i];
		}
	}
	return *this;
}


double Matrix::wyznacznik() const{
	if (r!=c) throw size_err();

	Matrix m(*this);
	double det=1;

	for(uint k=0; k<r-1; ++k){
			if(m.data[c*k + k]==0) throw zero_err();
			
			for(uint i=k+1; i<r; ++i){
				m.data[c*i + k] /= m.data[c*k + k];
			}
			for(uint i=k+1; i<r; ++i){
				for(uint j=k+1; j<r; ++j){ 
					m.data[c*i + j] -= (m.data[c*i + k]*m.data[c*k + j]); 
				}}}
	for (uint i=0; i<c; ++i) det*=m.data[i*c+i];
	//m.rysuj();
	return det;
	}


bool Matrix::operator==(const Matrix& m) const{
	if (c!=m.c || r!=m.r) return 0;
	for (uint i=0; i<r; ++i){
		for (uint j=0; j<c; ++j){
			if (m.data[INDEX] != data[INDEX]) return 0;
		}
	}
	return 1;
}


bool Matrix::operator!=(const Matrix& m) const{
	return !(*this==m);
}

