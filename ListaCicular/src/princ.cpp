//============================================================================
// Name        : ListaCircular.cpp
// Author      : Luizf
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "ListaCirc.hpp"

int main() {
	int i;
	int result;


	ListaCirc<int> l = ListaCirc<int>();
	for (i = 0; i < 10; i++) {

		l.adicionaEmOrdem(10-i);
	}
try {
	l.posicao(1);
		l.posicao(2);
		bool teste = l.menor(l.posicao(1), l.posicao(2));

} catch (int e) {
	return 1;
}




	return 0;
}
