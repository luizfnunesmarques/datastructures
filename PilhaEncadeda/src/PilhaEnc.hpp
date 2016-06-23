/* Copyright [2014] <Luiz Marques>
 * TestePilha.cpp
 */
#include "ListaEnc.hpp"
#define PILHAVAZIA -1
#define ERROPILHACHEIA -999
#define ERROPILHAVAZIA -998
#define ERROTAMPILHAINVALIDO -997

template<typename T>
class PilhaEnc: private ListaEnc<T> {
 private:
	T* items;
	void InicializaPilha();

 public:
	PilhaEnc<T>();
	void empilha(T dado);
	T desempilha();
	T topo();
	void limparPilha();
	bool PilhaVazia();
};

template<typename T>
void PilhaEnc<T>::empilha(T dado) {
	ListaEnc<T>::adicionaNoInicio(dado);
}

template<typename T>
T PilhaEnc<T>::desempilha() {
	return ListaEnc<T>::retiraDoInicio();
}

template<typename T>
T PilhaEnc<T>::topo() {
	if (ListaEnc<T>::listaVazia())
		throw ERROLISTAVAZIA;
	return ListaEnc<T>::pegaCabecaLista();
}

template<typename T>
void PilhaEnc<T>::limparPilha() {
	ListaEnc<T>::destroiLista();
}

template<typename T>
bool PilhaEnc<T>::PilhaVazia() {
	return ListaEnc<T>::listaVazia();
}

template<typename T>
PilhaEnc<T>::PilhaEnc() {
}
