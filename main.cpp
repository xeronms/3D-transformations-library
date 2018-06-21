#include <iostream>
#include <typeinfo>


struct A{

	double a; double b;
};


class B{
public:
	virtual ~B(){}
};

class D : public B{
};


int main(){

	int a =1;
	double b;
	A S;
	
	b = static_cast <double> (a);

	/*
		b = static_cast <double> (S); nie da sie
	
		int * c = static_cast <int*> (b);
	
		tez sie nie da.
		mozna tylko uzywac do 'normalnych typow'
	*/
	
	
	
	/* 
		const_cast - zdejmuje const ze wskaznika lub referencji na const
	*/
	
	int i =7;
	/* int * const p = &i; wskaznik na stałą - który można zmieniać
	*p = 3;
	stały wskaznik na zmienną - nie można zmieniać
	*/
	
	const int * p = &i;
	
	int *p2 = const_cast<int*> (p);
	
	
	
	/* 
		dynamic_cast - castuje w dół hierarchii dziedziczenia
		
		obiekt klasy bazowej chcemy zrzutowac na obiekt klasy pochodnej
		
		RTTI nie zadziała bez Vtable, wiec potrzebujemy funkcje wirtualna
	*/
	D d1;
	B& br = d1;
	D& dr = dynamic_cast<D&>(br);
	
	
	D d;
	B* bp = &d;
	D* dp = dynamic_cast<D*>(bp);
	
	/*
	const type_info& typObiektu = typeid(d);
	
	std::cout << typObiektu.name() << std::endl; 
	*/
	
	
	return 0;
}
