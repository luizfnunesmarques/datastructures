//============================================================================
// Name        : PilhaEncadeada.cpp
// Author      : Luizf
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "PilhaEnc.hpp"


using namespace std;


int main() {
	int ptrDado = 5;
	int *pointer;



	PilhaEnc<int> *myLst = new PilhaEnc<int>();
	try {
		bool tempTest = myLst->PilhaVazia();
			myLst->PilhaVazia();
			myLst->empilha(1);
			myLst->empilha(2);
			myLst->empilha(4);
			myLst->empilha(3);
			myLst->empilha(9);
			myLst->empilha(5);
			myLst->desempilha();
			myLst->limparPilha();
			int teste = myLst->topo();


	} catch (int e) {
	}

	return 0;
}
