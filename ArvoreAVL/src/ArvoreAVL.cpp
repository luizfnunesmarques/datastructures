//============================================================================
// Name        : ArvoreAVL.cpp
// Author      : Luizf
// Version     :
// Copyright   : 2015 GNU
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "NoAvl.hpp"
using namespace std;

int main() {
	NoAVL<int> *inteiro = new NoAVL<int>(10);

//	inteiro = inteiro->inserir(4, inteiro);
//	inteiro = inteiro->inserir(15, inteiro);
//	inteiro = inteiro->inserir(14, inteiro);
//	inteiro = inteiro->inserir(17, inteiro);
//	inteiro = inteiro->inserir(6, inteiro);
//	inteiro = inteiro->inserir(20, inteiro);
//	inteiro = inteiro->inserir(13, inteiro);
//	inteiro = inteiro->inserir(25, inteiro);
//	inteiro = inteiro->inserir(7, inteiro);
//	inteiro = inteiro->inserir(8, inteiro);
//	inteiro = inteiro->inserir(2, inteiro);
//	inteiro = inteiro->inserir(26, inteiro);
//	inteiro = inteiro->inserir(18, inteiro);
//
//	inteiro = inteiro->remover(inteiro, 26);
//	inteiro = inteiro->remover(inteiro, 25);
//	// Rotação dupla à Direita
//	int j = inteiro->getAltura();
//
//	j = *(inteiro->getEsquerda()->getEsquerda()->getEsquerda()->getDado());
//
//	j = *(inteiro->getEsquerda()->getEsquerda()->getDado());
//	j = *(inteiro->getEsquerda()->getDado());
//	j = *(inteiro->getEsquerda()->getDireita()->getDado());
//	j = *(inteiro->getEsquerda()->getDireita()->getDireita()->getDado());
//
//	j = 10, *(inteiro->getDado());
//	j = 13, *(inteiro->getDireita()->getEsquerda()->getEsquerda()->getDado());
//
//	j = *(inteiro->getDireita()->getEsquerda()->getDado());
//	j = *(inteiro->getDireita()->getDado());
//	j = *(inteiro->getDireita()->getDireita()->getEsquerda()->getDado());
//
//	j = *(inteiro->getDireita()->getDireita()->getDado());
//	j = *(inteiro->getDireita()->getDireita()->getDireita()->getDado());

	 //Simples direita
	 inteiro = inteiro->inserir(5, inteiro);
	 inteiro = inteiro->inserir(15, inteiro);
	 inteiro = inteiro->inserir(14, inteiro);
	 inteiro = inteiro->inserir(16, inteiro);
	 inteiro = inteiro->inserir(6, inteiro);
	 inteiro = inteiro->inserir(17, inteiro);
	 inteiro = inteiro->inserir(13, inteiro);
	 inteiro = inteiro->inserir(18, inteiro);
	 inteiro = inteiro->inserir(7, inteiro);
	 inteiro = inteiro->inserir(8, inteiro);
	 inteiro = inteiro->inserir(3, inteiro);
	 inteiro = inteiro->inserir(19, inteiro);
	 inteiro = inteiro->remover(inteiro, 15);

	 int j = inteiro->getAltura();
	 j = *(inteiro->getEsquerda()->getEsquerda()->getEsquerda()->getDado());
	 j = *(inteiro->getEsquerda()->getEsquerda()->getDado());
	 j = *(inteiro->getEsquerda()->getDado());
	 j = *(inteiro->getEsquerda()->getDireita()->getDado());
	 j = *(inteiro->getEsquerda()->getDireita()->getDireita()->getDado());
	 j = *(inteiro->getDado());
	 j = *(inteiro->getDireita()->getEsquerda()->getEsquerda()->getDado());
	 j = *(inteiro->getDireita()->getEsquerda()->getDado());
	 j = *(inteiro->getDireita()->getDado());
	 j = *(inteiro->getDireita()->getDireita()->getEsquerda()->getDado());
	 j = *(inteiro->getDireita()->getDireita()->getDado());
	 j = *(inteiro->getDireita()->getDireita()->getDireita()->getDado());

	/*   int altura =  inteiro->getAltura();
	 int conteudo =  *(inteiro->getDado());
	 conteudo =*(inteiro->getEsquerda()->getDado());
	 conteudo= *(inteiro->getDireita()->getDado());*/

//	int h;
//	int j;
//	 for (h = 1; h < 10; h++) {
//	        inteiro = inteiro->inserir(h, inteiro);
//	    }
//	    for (h = 1; h < 11; h++) {
//	      inteiro->busca(h, inteiro);
//	    }
//	    for (h = 11; h < 20; h++) {
//	       inteiro->busca(h, inteiro);
//	    }
	return 0;
}
