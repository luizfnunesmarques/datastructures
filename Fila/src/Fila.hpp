#define FILAVAZIA -1
#define ERROFILAVAZIA -998
#define ERROFILACHEIA -999
#define ERROTAMNAODEFINIDO -997


template <typename T>
class Fila {
 private:
	int nTamFila;
	int nUltimo;
	T items[];

 public:
	Fila();
	/**
	 * @brief Construtor
	 * @details Constrói uma classe de gerenciamento fila, para qualquer objeto <T> .
	 * 
	 * @param tam Tamanho máximo da fila.
	 */
	Fila<T>(int tam);
	/**
	 * @brief Inclui um item na fila.
	 * @details 
	 * 
	 * @param dado Dado <T> a ser inserido.
	 */
	void inclui(T dado);
	/**p
	 * @brief Retira o primeiro item inserido na fila.
	 * @return Item retirado.
	 */
	T retira();

	/**
	 * @brief Retira o ultimo item inserido na fila.
	 * @return Item retirado.
	 */
	T ultimo();
	
	/**
	 * @brief Pega a posiçao do último item da lista.
	 * @details 
	 * @return Int
	 */
	int getUltimo();

	/**
	 * @brief Testa se a filha está cheia.
	 * @return BOOL
	 */
	bool filaCheia();

	/**
	 * @brief Testa se a fila está vazia.
	 * @return bool
	 */
	bool filaVazia();

	/**
	 * @brief Inicializa a fila com os dados necessários.
	 * @details [long description]
	 */
	void inicializaFila();
};

template<typename T>
Fila<T>::Fila() {
}


template<typename T>
Fila<T>::Fila(int tam) {
	if (tam < 1)
		throw ERROTAMNAODEFINIDO;

	nTamFila = tam;
	inicializaFila();
}

template<typename T>
void Fila<T>::inclui(T dado) {
	if (filaCheia())
		throw ERROFILACHEIA;

	nUltimo++;
	items[nUltimo] = dado;
}

template<typename T>
T Fila<T>::retira() {
	T objAux = items[0];

	for (int i = 0; i < nUltimo -1; --i) {
		items[i] = items[i+1];
	}
	nUltimo--;
	return objAux;
}

template<typename T>
T Fila<T>::ultimo() {
	return items[nUltimo];	
}


template<typename T>
int Fila<T>::getUltimo() {
	if (nUltimo == FILAVAZIA)
		throw ERROFILAVAZIA;

	return nUltimo;
}

template<typename T>
bool Fila<T>::filaCheia() {
	return nUltimo == nTamFila-1;
}


template<typename T>
void Fila<T>::inicializaFila() {
	nUltimo = -1;
}

template<typename T>
bool Fila<T>::filaVazia() {
	return nUltimo == FILAVAZIA;
}





