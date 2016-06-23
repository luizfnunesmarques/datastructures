//============================================================================
// Name        : ArvPercurso.cpp
// Author      : Luizf
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "NoBinario.hpp"

using namespace std;

int main() {
NoBinario<int>* inteiro = new NoBinario<int>(10);
//	int i = *inteiro->busca(10, inteiro);
	inteiro->inserir(8, inteiro);
//	i = *inteiro->busca(5, inteiro);
	inteiro->inserir(9, inteiro);
//	i = *inteiro->busca(20, inteiro);
	inteiro->inserir(11, inteiro);
//	i = *inteiro->busca(3, inteiro);
	inteiro->inserir(12, inteiro);
//	i = *inteiro->busca(16, inteiro);
//	i = *inteiro->busca(14, inteiro);
//	}

	int i;



	    inteiro->posOrdem(inteiro);

	cout << "" << endl; // prints 

	return 0;
}
