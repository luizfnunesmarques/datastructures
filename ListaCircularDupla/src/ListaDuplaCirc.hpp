/* Copyright [2014] <Luiz Marques>
 * ListaDuplaCirc.cpp
 */
#include "Elemento.hpp"
#define ERROLISTAVAZIA -2;
#define ERROPOSICAO -3;
#define ERROLISTACHEIA -1;

template<typename T>
class ListaDuplaCirc {
private:
	int qtdElementos;
	Elemento<T>* head;
	void ValidarPosicaoParaInsercao(const int pos) {
		if (pos == 0)
			return;

		if ((pos > qtdElementos) || pos < 0)
			throw ERROPOSICAO;
	}
	void adicionaElementoInicial(const T&dado) {
		Elemento<T> *novo = new Elemento<T>(dado, head, head);
		if (novo == NULL)
			throw ERROLISTACHEIA;
		this->head->setProximo(novo);
		this->head->setAnterior(novo);
		qtdElementos++;
	}

	void adicionaNaCauda(const T& dado) {
		Elemento<T> *cauda = this->head->getProximo();

		for (int i = 1; i < qtdElementos; ++i) {
			cauda = cauda->getProximo();
		}

		Elemento<T> *novo = new Elemento<T>(dado, NULL, NULL);
		novo->setProximo(head);
		novo->setAnterior(cauda);
		head->setAnterior(novo);
		cauda->setProximo(novo);
		qtdElementos++;
	}
public:
	ListaDuplaCirc<T>();
	~ListaDuplaCirc() {
		;
	}

	void adicionaNoInicioDuplo(const T& dado) {
		if (this->listaVazia()) {
			adicionaElementoInicial(dado);
			return;
		}
		Elemento<T> *novo = new Elemento<T>(dado, head, head);
		Elemento<T> *primeiro = head->getProximo();
		primeiro->setAnterior(novo);
		novo->setProximo(primeiro);
		head->setProximo(novo);
		if (novo == NULL)
			throw ERROLISTACHEIA;
		qtdElementos++;
	}
	T retiraDoInicioDuplo() {
		if (listaVazia()) {
			throw ERROLISTAVAZIA;
		}

		T retorno = head->getInfo();
		Elemento<T>* del = head;
		head = head->getProximo();
		if (head != NULL) {
			head->setAnterior(NULL);
		}

		delete del;
		qtdElementos--;
		return retorno;

	}
	void eliminaDoInicioDuplo() {
	}
	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
		ValidarPosicaoParaInsercao(pos);

		if (pos == 0)
			return adicionaNoInicioDuplo(dado);

		Elemento<T> *novo;
		Elemento<T> *anterior;
		novo = new Elemento<T>(dado, NULL, NULL);
		anterior = head->getProximo();

		for (int i = 0; i < pos - 1; i++) {
			anterior = anterior->getProximo();
		}
		novo->setProximo(anterior->getProximo());
		novo->setAnterior(anterior);
		Elemento<T> *proximo = anterior->getProximo();
		proximo->setAnterior(novo);
		anterior->setProximo(novo);
		qtdElementos++;
	}
	int posicaoDuplo(const T& dado) {
		if (listaVazia())
			throw ERROLISTAVAZIA;

		int i = 0;
		Elemento<T> *walker = head->getProximo();
		while (i < qtdElementos) {
			if (walker->getInfo() == dado)
				return i;
			walker = walker->getProximo();
			i++;
		}
		throw ERROPOSICAO;
	}
	T* posicaoMemDuplo(const T& dado) {
	}
	bool contemDuplo(const T& dado) {
		try {
			this->posicaoDuplo(dado);
			return true;
		} catch (int e) {
			return false;
		}
		return false;
	}

	T retiraDaPosicaoDuplo(int pos) {
		if (listaVazia())
			throw ERROLISTAVAZIA;

		if (pos > qtdElementos+1)
			throw ERROPOSICAO;

		if (pos == 0)
			return retiraDoInicioDuplo();

		Elemento<T>* anterior = head;
		for (int i = 0; i < pos; i++) {
			anterior = anterior->getProximo();
		}

		Elemento<T>* walkDead = anterior->getProximo();
		T retorno = walkDead->getInfo();
		anterior->setProximo(walkDead->getProximo());
		if (walkDead->getProximo() != NULL)
			walkDead->getProximo()->setAnterior(anterior);

		delete walkDead;
		qtdElementos--;
		return retorno;
	}
	void adicionaDuplo(const T& dado) {
		if (qtdElementos == 0) {
			this->adicionaNoInicioDuplo(dado);
			return;
		}
		this->adicionaNaCauda(dado);
	}
	T retiraDuplo() {
		return this->retiraDaPosicaoDuplo(qtdElementos - 1);
	}
	T retiraEspecificoDuplo(const T& dado) {
		return retiraDaPosicaoDuplo(posicaoDuplo(dado));
	}
	T mostra(int pos) {
	}
	void adicionaEmOrdem(const T& data) {
		if (listaVazia()) {
			adicionaNoInicioDuplo(data);
			return;
		}
		Elemento<T> *primeiro = head->getProximo();
		if (menor(data, primeiro->getInfo())) {
			adicionaNoInicioDuplo(data);
			return;
		}

	}
	int verUltimo() {
		head->getAnterior();
	}
	bool listaVazia() {
		return qtdElementos == 0;
	}
	bool igual(T dado1, T dado2) {
		return dado1 == dado2;
	}
	bool maior(T dado1, T dado2) {
		return dado1 >= dado2;
	}
	bool menor(T dado1, T dado2) {
		return dado1 <= dado2;
	}
	void destroiListaDuplo() {
		if ((this->head == NULL))
			return;

		Elemento<T> *next, *walkingdead;
		walkingdead = head->getProximo();
		for (int i = 0; i < qtdElementos; ++i) {
			next = walkingdead->getProximo();
			delete (walkingdead);
			walkingdead = next;
		}
		qtdElementos = 0;
	}
};
template<typename T>
ListaDuplaCirc<T>::ListaDuplaCirc() {
	qtdElementos = 0;
	this->head = new Elemento<T>(0, NULL, NULL);
}
