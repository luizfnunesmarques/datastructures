#ifndef NOBINARIO_H_
#define NOBINARIO_H_

#include <cstdio>
#include <vector>

template<typename T>
class NoBinario {

private:
	T* dado;
	NoBinario<T>* esquerda;
	NoBinario<T>* direita;
	virtual NoBinario<T>* balanco_insere(NoBinario<T>* arv) {
		return arv;
	}
	; // Para ajudar nos herancas
	virtual NoBinario<T>* balanco_remove(NoBinario<T>* arv) {
		return arv;
	}
	; // Para ajudar nos herancas
	  //std::vector<NoBinario<T> > elementos; // No lugar dos prints

public:
	NoBinario<T>(const T& dado) :
			dado(new T(dado)), esquerda(NULL), direita(NULL) {
	}
	virtual ~NoBinario<T>() {
	}
	T* getDado() {
	}
	NoBinario<T>* getElementos() {
	}
	T* busca(const T& dado, NoBinario<T>* arv) {
	}
	NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv) {
		bool bEsquerda;

		bEsquerda = (dado < *arv->dado);
		NoBinario<T> *no;

		if (bEsquerda) {
			no = arv->esquerda;
		} else {
			no = arv->direita;
		};

		if (!(no == NULL)) {
			return no->inserir(dado, no);
		}

		NoBinario<T> *novoNo = new NoBinario<T>(dado);

		if (bEsquerda) {
			arv->esquerda = novoNo;
		} else {
			arv->direita = novoNo;
		}
		return novoNo;
	}

	NoBinario<T>* remover(NoBinario<T>* arv, const T& dado) {
	}
	NoBinario<T>* minimo(NoBinario<T>* nodo) {
	}
	void preOrdem(NoBinario<T>* nodo) {
	}
	void emOrdem(NoBinario<T>* nodo) {
	}
	void posOrdem(NoBinario<T>* nodo) {
	}
};

#endif /* NOBINARIO_HPP_ */
