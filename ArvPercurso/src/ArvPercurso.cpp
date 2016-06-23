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
	cout << "" << endl; // prints 
	NoBinario<int> *teste = new NoBinario<int>(90);

	teste->inserir(50, teste);
	teste->inserir(200, teste);
	teste->inserir(90, teste);

	return 0;
}
