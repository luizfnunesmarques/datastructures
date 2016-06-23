//============================================================================
// Name        : ListaCircularDupla.cpp
// Author      : Luizf
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ListaDuplaCirc.hpp"
#include "Elemento.hpp"

using namespace std;

int main() {

	ListaDuplaCirc<int> l = ListaDuplaCirc<int>();
	for (int i = 1; i < 5; i++) {

		l.adicionaNoInicioDuplo(i);
	}
	try {
		l.retiraDaPosicaoDuplo(0);
		l.retiraDaPosicaoDuplo(1);

	} catch (int e) {
		return 1;
	}
	cout << "" << endl; // prints 
	return 0;
}
