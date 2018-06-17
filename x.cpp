#include <vector>
#include <iostream>
#include <list>


int main(int argc, char* argv[]){
	
	std::list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
	
	int tab[] = {1,3,5,2,31,78};
	
	
	//std::vector<int> vi(li.begin(), li.end());  // do wektora zostaja wkopiowane wszystkie elementy listy 
	std::vector<int> vi(tab, tab + sizeof(tab)/sizeof(tab[0]) );
	//std::vector<int> vi(10); // daje nam 10 domyślnych elementów, czyli int(). daje takie samo capacity
	//std::vector<int> vi(10,7); // daje nam 10 klonów siódemek
	//std:vector<int> vi2((std::istream_iterator<int>(std::cin), std::istream_iterator<int>())); // tworzy wektor ze strumienia
	vi.push_back(14);
	
	std::cout << sizeof(vi) <<std::endl; // zawsze wazy 24 
	
	//vi.reserve(50); // rezerwujemy pamiec na 50 elementow
	
	std::cout << vi.size() << std::endl << vi.max_size() << std::endl <<  vi.capacity() << std::endl; // vi.empty() uzywac
	// capacity() - ile pomiesci obecnie elementow. dla pustego wektora mamy 0
	
	for(int i =0; i<100; ++i){
		std::cout << vi.size() << "," << vi.capacity() << std::endl;
		
		// capacity, jak brakuje pamieci, to rośnie zawsze dwukrotnie ( zawsze w stl )
		// realokacja pamieci
		vi.push_back(i);
	}
	
	
	int idx = 0;
	for (std::vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) { // wazne zeby bylo it!=vi.end(),  oraz ++it
		std::cout << idx++ << ":" << *it << std::endl;
	}
	
	
	// operator [] pozwala na dostep, ale nie sprawdza czy wyszlismy poza zakres - metoda at() sprawdza i rzuca wyjątek, ale jest wolna
	// operator == 
	// operatory > i < porownują po elemencie, ten jest mniejszy ktory ma mniejszy pierwszy element ktorym sie roznią
	// metoda swap() podmienia obszary pamieci wskazywane przez kontenery (zmienia wskaźniki, elementy w swoim miejscu)
	/*
	wektor : taka tablica dynamiczna
	szybkie jest wstawianie na koniec, nie na srodek.
	jak brakuje miejsca to sie resize'uje

	metoda pop() nie zmniejsza pamięci
	
	w nowym standardzie mamy metode shrink_to_fit()

	queue:
	daje gwarancje ze gdy sie rozszerza to nie zarealokuje pamieci tak, ze zmieni nam adresy i wskazniki nie beda działały




	tworzy zmienna anonimow
	*/
}
