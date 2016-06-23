/* Copyright [2014] <Luiz Marques>
 * ListaDupla.cpp
 */
#include "Elemento.hpp"
#define ERROLISTAVAZIA -2;
#define ERROPOSICAO -3;
#define ERROLISTACHEIA -1;

template<typename T>
class ListaDupla {
private:
	Elemento<T>* head;
	void validarPosicaoParaInsercao(int pos) {
		if (pos == 0)
			return;

		if ((pos > size) || pos < 0)
			throw ERROPOSICAO;
	}

	virtual void adicionaElementoInicial(const T& dado) {
		head = new Elemento<T>(dado, NULL, NULL);

		size++;
		return;
	}
protected:
	virtual void inicializaCabecaLista() {
		this->head = NULL;
	}
	virtual Elemento<T>* getHead() {
		return head;
	}

	virtual void setHead(Elemento<T>* elem) {
		this->head = elem;

	}
	int size;
public:
	ListaDupla() {
		size = 0;
		this->inicializaCabecaLista();
	}

	~ListaDupla() {
		destroiListaDuplo();
	}

	virtual void adicionaNoInicioDuplo(const T& dado) {
		validarPosicaoParaInsercao(0);

		if (this->getHead() == NULL) {
			this->adicionaElementoInicial(dado);
			return;
		}

		Elemento<T> *proximo = this->getHead()->getProximo();
		Elemento<T>* novo = new Elemento<T>(dado, NULL, NULL);

		if (!(proximo == NULL))
			proximo->setAnterior(novo);

		novo->setProximo(this->getHead());
		this->getHead()->setAnterior(novo);
		setHead(novo);
		size++;
	}

	T retiraDoInicioDuplo() {
		if (listaVazia())
			throw ERROLISTAVAZIA;

		Elemento<T> *deleted;
		T dadoRetirado;
		deleted = head;
		dadoRetirado = deleted->getInfo();
		Elemento<T> *proximo = head->getProximo();
		if (!(proximo == NULL)) {
			proximo->setAnterior(NULL);
			head = proximo;
		}
		delete (deleted);
		size--;
		return dadoRetirado;
	}

	void eliminaDoInicioDuplo() {
	}

	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
		validarPosicaoParaInsercao(pos);

		if (pos == 0)
			return this->adicionaNoInicioDuplo(dado);

		Elemento<T> *novo;
		Elemento<T> *anterior;
		Elemento<T> *proximo;

		novo = new Elemento<T>(dado, NULL, NULL);
		anterior = head;

		for (int i = 0; i < pos - 1; i++) {
			anterior = anterior->getProximo();
		}
		novo->setProximo(anterior->getProximo());
		novo->setAnterior(anterior);
		proximo = anterior->getProximo();
		anterior->setProximo(novo);

		if (!(proximo == NULL))
			proximo->setAnterior(novo);

		size++;
	}

	int posicaoDuplo(const T& dado) {
		if (listaVazia())
			throw ERROLISTAVAZIA;

		int i = 0;
		Elemento<T> *walker = head;
		while (i < size) {
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
			posicaoDuplo(dado);
			return true;
		} catch (int e) {
			return false;
		}
	}

	T retiraDaPosicaoDuplo(int pos) {
		if (listaVazia())
			throw ERROLISTAVAZIA;

		if (pos > (size - 1))
			throw ERROPOSICAO;

		if (pos == 0)
			return retiraDoInicioDuplo();

		Elemento<T> *walkingDead = head;
		Elemento<T> *anterior;
		for (int i = 0; i < pos; ++i) {
			anterior = walkingDead;
			walkingDead = walkingDead->getProximo();
		}
		Elemento<T> *proximo = walkingDead->getProximo();

		if (!(proximo == NULL)) {
			proximo->setAnterior(anterior);
			anterior->setProximo(proximo);
		}

		T retorno = walkingDead->getInfo();
		delete (walkingDead);
		size--;
		return retorno;
	}

	void adicionaDuplo(const T& dado) {
		return adicionaNaPosicaoDuplo(dado, size);
	}

	T retiraDuplo() {
		if (listaVazia())
			throw ERROLISTAVAZIA;
		return retiraDaPosicaoDuplo(size - 1);
	}

	T retiraEspecificoDuplo(const T& dado) {
		int pos = posicaoDuplo(dado);

		if (pos == 0)
			return retiraDoInicioDuplo();

		if (pos == size - 1)
			return retiraDaPosicaoDuplo(size - 1);

		return retiraDaPosicaoDuplo(pos);
	}

	T mostra(int pos) {
	}

	void adicionaEmOrdem(const T& data) {
		if (listaVazia()) {
			adicionaNoInicioDuplo(data);
			return;
		}

		if (menor(data, head->getInfo())) {
			adicionaNoInicioDuplo(data);
			return;
		}

		Elemento<T> *walker = head;
		for (int i = 0; i < size; ++i) {
			if (menor(data, walker->getInfo())) {
				adicionaNaPosicaoDuplo(data, i);
				return;
			}
		}
		adicionaDuplo(data);
	}

	int verUltimo() {
	}

	bool listaVazia() {
		return size == 0;
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
		if (head == NULL)
			return;

		Elemento<T> *next, *walkingdead;
		walkingdead = head;
		for (int i = 1; i <= size; ++i) {
			next = walkingdead->getProximo();
			delete (walkingdead);
			walkingdead = next;
		}
		size = 0;
	}
};

