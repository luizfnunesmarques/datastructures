/* Copyright [2014] <Luiz Marques>
 * Elemento.cpp
 */

#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template<typename T>
class Elemento {
 private:
	T *info;
	Elemento<T>* _next;
	Elemento<T>* _prev;

 public:
	Elemento(const T& info, Elemento<T>* next, Elemento<T>* prev) :
			info(new T(info)), _next(next), _prev(prev) {
	}

	~Elemento() {
		delete info;
	}

	Elemento<T>* getProximo() const {
		return _next;
	}

	Elemento<T>* getAnterior() const {
			return _prev;
		}

	T getInfo() const {
		return *info;
	}

	void setProximo(Elemento<T>* next) {
		_next = next;
	}

	void setAnterior(Elemento<T>* prev) {
		_prev = prev;
	}
};

#endif
