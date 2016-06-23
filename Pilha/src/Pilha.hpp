/* Copyright [2014] <Luiz Marques>
 * TestePilha.cpp
 */

#define PILHAVAZIA -1
#define ERROPILHACHEIA -999
#define ERROPILHAVAZIA -998
#define ERROTAMPILHAINVALIDO -997

template<typename T>
class Pilha {
 private:
    int nTOPO;
    int nMaxPilha;
    T* items;
    void InicializaPilha();


 public:
    Pilha();
    Pilha<T>(int tam);
    void empilha(T dado);
    T desempilha();
    T topo();
    int getPosTopo();
    void limparPilha();
    bool PilhaVazia();
    bool PilhaCheia();
};

template<typename T>
void Pilha<T>::empilha(T dado) {
	if (PilhaCheia())
		throw ERROPILHACHEIA;

	nTOPO = nTOPO+1;
	items[nTOPO] = dado;
}

template<typename T>
T Pilha<T>::desempilha() {
	if (PilhaVazia())
		throw ERROPILHAVAZIA;

	T objRetirado = items[nTOPO];
	nTOPO = nTOPO - 1;
	return objRetirado;
}

template<typename T>
T Pilha<T>::topo() {
	if (PilhaVazia())
			throw ERROPILHAVAZIA;
	return items[nTOPO];
}

template<typename T>
int Pilha<T>::getPosTopo() {
	if (PilhaVazia())
		throw ERROPILHAVAZIA;
	return nTOPO;
}

template<typename T>
void Pilha<T>::limparPilha() {
	nTOPO = -1;
}

template<typename T>
bool Pilha<T>::PilhaVazia() {
	return nTOPO == PILHAVAZIA;
}

template<typename T>
Pilha<T>::Pilha(int tam) {
	if (tam < 0)
		throw ERROTAMPILHAINVALIDO;
	nMaxPilha = tam -1;
	InicializaPilha();
}

template<typename T>
Pilha<T>::Pilha() {
}

template<typename T>
bool Pilha<T>::PilhaCheia() {
	return nTOPO == nMaxPilha;
}
template<typename T>
void Pilha<T>::InicializaPilha() {
	nTOPO = -1;
	items = new T[nMaxPilha];
}











