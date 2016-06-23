//============================================================================
// Name        : PilhaDrop.cpp
// Author      : Luizf
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Pilha.hpp"
using namespace std;

int main() {
	Pilha<int> fi = Pilha<int>(5);
	bool test = fi.PilhaCheia();
	test = fi.PilhaVazia();
	fi.empilha(10);
	fi.empilha(20);
	fi.empilha(30);
	bool test = fi.PilhaCheia();
	test = fi.PilhaVazia();
	fi.empilha(90);
	int nTam = fi.getPosTopo();



	return 0;
}
