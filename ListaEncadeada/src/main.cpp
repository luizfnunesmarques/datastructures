#include "elemento.hpp"
#include "ListaEnc.hpp"
#include <exception>
#include <iostream>
using namespace std;

int main() {

	int ptrDado = 5;
	int *pointer;

	ListaEnc<int> *myLst = new ListaEnc<int>();
	bool testeVazia = myLst->contem(ptrDado);
	try {
		myLst->eliminaDoInicio();
	} catch (int e) {
		cout << "erro";
	}
	testeVazia = myLst->listaVazia();
	int pos;
	myLst->adicionaNoInicio(50);
	myLst->adiciona(30);
	myLst->adiciona(90);
	int ret = myLst->retira();
	ret = myLst->retiraDaPosicao(1);
	try {
		myLst->retiraDaPosicao(5);
	} catch (int e) {
		cout << "erro";
	}
	ret = 2;
}

