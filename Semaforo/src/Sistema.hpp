//============================================================================
// Name        : Simulador
// Author      : Luizf
// Version     : 1.2
// Copyright   : 
// Description : Simulador de semároforos.
//============================================================================
#ifndef SISTEMA_HPP_
#define SISTEMA_HPP_
#include "Pista/veiculo/Carro.hpp"
#include "Semaforo/Central.hpp"
#include "Pista/Pista.hpp"
#include "Pista/Sumidouro.hpp"
#include "Pista/Fonte.hpp"
#include "core/Lista.hpp"
#include "core/ListaEnc.hpp"
#include "core/ListaCirc.hpp"
#include "Relogio.hpp"
#include "Eventos/EntraCarro.hpp"
#include "Eventos/EventoSemaforo.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class Sistema {
public:
	Sistema(int intervaloSemaforos, int duracao) {
		this->intervaloSemaforo = intervaloSemaforos;
		this->duracao = duracao;
		criarRelogio();
		criarSemaforos();
		//Cria todas as pistas, basico.
		inicializaPistas();
	}
	void iniciarSimulacao() {
		central->abrirPrimeiroSinal();
		relogio->AdicionaEvento(
				new EventoSemaforo(intervaloSemaforo, intervaloSemaforo,
						central, relogio));

		Evento* eventoAtual;
		Evento* novoEvento;

		int t = 0;

		while (t < duracao) {
			eventoAtual = relogio->proximoEvento();
			t = eventoAtual->getTempoExecucao();

			if (t > duracao)
				break;

			novoEvento = eventoAtual->Executar();
			if (!(novoEvento == NULL))
				relogio->AdicionaEvento(novoEvento);

			delete eventoAtual;


		};

		cout << sumidouros->retira()->QuantidadeCarrosSairam() << endl;
		cout << sumidouros->retira()->QuantidadeCarrosSairam() << endl;
		cout << sumidouros->retira()->QuantidadeCarrosSairam() << endl;
		cout << sumidouros->retira()->QuantidadeCarrosSairam() << endl;
		cout << sumidouros->retira()->QuantidadeCarrosSairam() << endl;
		cout << sumidouros->retira()->QuantidadeCarrosSairam() << endl;

	}
private:
	int intervaloSemaforo;
	int duracao;
	ListaEnc<Sumidouro*>* sumidouros;
	Relogio* relogio;
	Central* central;

	void criarSemaforos() {
		central = new Central;

	}

	void inicializaPistas() {
		Semaforo* semO1C1Leste = new Semaforo('a');
		central->adiciona(semO1C1Leste);
		Semaforo* semS1S2Norte = new Semaforo('b');
		central->adiciona(semS1S2Norte);
		Semaforo* l1C1Oeste = new Semaforo('c');
		central->adiciona(l1C1Oeste);
		Semaforo* n1N2Sul = new Semaforo('d');
		central->adiciona(n1N2Sul);

		sumidouros = new ListaEnc<Sumidouro*>;
		Sumidouro* o1Oeste = new Sumidouro(22, 2000);
		sumidouros->adiciona(o1Oeste);
		Sumidouro* l1Leste = new Sumidouro(8, 400);
		sumidouros->adiciona(l1Leste);
		Sumidouro* n1Norte = new Sumidouro(17, 500);
		sumidouros->adiciona(n1Norte);
		Sumidouro* n2Norte = new Sumidouro(11, 500);
		sumidouros->adiciona(n2Norte);
		Sumidouro* s1Sul = new Sumidouro(17, 500);
		sumidouros->adiciona(s1Sul);
		Sumidouro* s2Sul = new Sumidouro(11, 500);
		sumidouros->adiciona(s2Sul);

		Pista* c1Leste = new Pista(l1Leste, 4, n2Norte, 3, s2Sul, 3, 17, 300,
				semO1C1Leste);
		semO1C1Leste->definirConexaoB(c1Leste);

		Pista* c1Oeste = new Pista(o1Oeste, 4, n1Norte, 3, s1Sul, 3, 17, 300,
				l1C1Oeste);
		l1C1Oeste->definirConexaoB(c1Oeste);

		ListaEnc<Fonte*>* pistasTemp = new ListaEnc<Fonte*>;

		Fonte* o1Leste = new Fonte(c1Leste, 8, n1Norte, 1, s1Sul, 1, 22, 2000,
				semO1C1Leste, 10, 2);
semO1C1Leste->definirConexaoA(o1Leste);
		pistasTemp->adiciona(o1Leste);

		Fonte* s1Norte = new Fonte(c1Leste, 8, n1Norte, 1, o1Oeste, 1, 17, 500,
				semS1S2Norte, 30, 7);
		semS1S2Norte->definirConexaoA(s1Norte);
		pistasTemp->adiciona(s1Norte);

		Fonte* s2Norte = new Fonte(l1Leste, 4, s2Sul, 3, c1Oeste, 3, 11, 500,
				semS1S2Norte, 60, 15);
		semS1S2Norte->definirConexaoB(s2Norte);
		pistasTemp->adiciona(s2Norte);

		Fonte* n1Sul = new Fonte(c1Leste, 8, o1Oeste, 1, s1Sul, 1, 17, 500,
				n1N2Sul, 20, 5);
		n1N2Sul->definirConexaoA(n1Sul);
		pistasTemp->adiciona(n1Sul);

		Fonte* n2Sul = new Fonte(l1Leste, 4, c1Oeste, 3, s2Sul, 3, 11, 500,
				n1N2Sul, 20, 5);
		n1N2Sul->definirConexaoB(n2Sul);
		pistasTemp->adiciona(n2Sul);

		Fonte* l1Oeste = new Fonte(n2Norte, 4, c1Leste, 3, s2Sul, 3, 8, 400,
				l1C1Oeste, 10, 2);
		l1C1Oeste->definirConexaoA(l1Oeste);
		pistasTemp->adiciona(l1Oeste);

		Fonte* pistaTemp = pistasTemp->retiraDoInicio();
		for (int i = 0; i < 5; ++i) {
			int tempoEntradaNovoCarro = pistaTemp->TempoEntradaNovoCarro();
			relogio->AdicionaEvento(
					new EntraCarro(tempoEntradaNovoCarro, relogio, pistaTemp));
			pistaTemp = pistasTemp->retiraDoInicio();
		}
	}

	void criarRelogio() {
		this->relogio = new Relogio;
	}
};

#endif
