#include <vector>
#include <set>
#include <iostream>

using std::pair;

//kontenery, dzialanie asocjacyjne:

void wektpor_a_set(){

	std::vector<int> v;
	std::set<int, std::greater<int> > s;
	int i;
	
	while ( 1 ){
		std::cin >> i;
		
		if ( i < 0 ) break;
		
		v.push_back(i);
		s.insert(i);
		
	}
	
	
	for( std::vector<int>::iterator it = v.rbegin(); it!=v.rend(); ++it){ // kolejnosc - tak jak podamy
		
		std::cout << *it << std::endl;
	}
	
	for( std::set<int>::iterator it2 = s.begin(); it2 != s.end(); ++it2){ // od najmniejszej do najwiekszej
		
		std::cout << *it2 << std::endl; // iterator do set'a nie zmienia elementow
	}
	
}


class Cmp{

	bool operator() ( const pair<double,double>& p1, const pair<double,double>& p2 ) const {
	
			// double powinny byc porownywane na epsilon (eps-granice wokol wartosci)
	
			double r1 = p1.first*p1.first + p1.second*p1.second;
			
			double r2 = p2.first*p2.first + p2.second*p2.second; 
		
			if ( ( r1 ) < ( r2 ) ) return true; // same kwadraty, nie pierwiastkujemy
			
			if ( ( r2 ) < ( r1 ) ) return false; // uzywamy operatora <
			
			if ( p1.first < p2.first ) return true;	
			
			if ( p1.first > p2.first ) return false;
			
			return ( p1.second < p2.second );	
					
	}
};


int main (){

	/* allokator - drugi parametr szablonu wektora np vector<int, alokator>
	 allocate(), construct(), mozna pisac wlasne alokatory
	
	set ma 3 parametry
	komparator - funktor porownujacy 2 elementy ( domyslnym jest less<int>(T) )
	allokator
	
	
	*/
	
	wektor_a_set();
	
	std::set <pair<double, double>, Cmp > s;
	
	s.insetr(pair(2,2));
	s.insert(pair(5,5));
	
	for( std::set<int>::iterator it3 = s.begin(); it3 != s.end(); ++it3){
		
		std::cout << *it3 << std::endl;
	}
	
	return 0;
}
