#include "aeroporto.h"

/**
 * aeroporto.c
 * Implementação das funções do aeroporto.h
 * Descrições em aeroporto.h
 **/
sem_t pista; //semafoto da pista
 
aeroporto_t* iniciar_aeroporto (size_t* args, size_t n_args) {
	return NULL;
}

void aproximacao_aeroporto (aeroporto_t* aeroporto, aviao_t* aviao) {
	// local onde os avioes para pousar irão esperar

}

void pousar_aviao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// quando uma pista estiver desocupada
}

void acoplar_portao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// aviao se dirige até aqui apos o pouso(embarque/desembarque) - apenas um aviao por vez (?)
	// n portoes - definido no main
}

void transportar_bagagens (aeroporto_t* aeroporto, aviao_t* aviao) {
	// retirar as bagagens do aviao - onde estao definidas quantas bagagens tem cada aviao?

}

void adicionar_bagagens_esteira (aeroporto_t* aeroporto, aviao_t* aviao) {
	// esteira tem a capacidade de 200 bagagens
}

void decolar_aviao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// desocupar a pista
}

int finalizar_aeroporto (aeroporto_t* aeroporto) {
	return 0;
}
