//============================================================================
// Name        : TesteListaDupla.cpp
// Author      : Luizf
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <exception>
#include "Sistema.hpp"

using namespace std;

int main() {
	Sistema *sistema = new Sistema(250, 2592);
	sistema->iniciarSimulacao();
	return 0;


}
