#include "aeroporto.h"

/**
 * aeroporto.c
 * Implementação das funções do aeroporto.h
 * Descrições em aeroporto.h
 **/
sem_t pista; //semafoto da pista
 
aeroporto_t* iniciar_aeroporto (size_t* args, size_t n_args) {
	aeroporto_t aeroporto*;
	aeroporto = (aeroporto_t*)malloc(sizeof(aeroporto_t));
	aeroporto->n_pistas = args[0];
	aeroporto->n_portoes = args[1];
	aeroporto->n_esteiras = args[2];
	aeroporto->n_max_avioes_esteira = args[3];
	aeroporto->t_pouso_decolagem = args[4];
	aeroporto-> t_remover_bagagens= args[5];
	aeroporto->t_inserir_bagagens = args[6];
	aeroporto->t_bagagens_esteira = args[7];
	fila_ordenada_t fila_pousar = criar_fila();
	fila_ordenada_t fila_portao = criar_fila();
	return aeroporto;
}

void aproximacao_aeroporto (aeroporto_t* aeroporto, aviao_t* aviao) {
	// local onde os avioes para pousar irão esperar
	bool no_ar = true;
	//inserir aviao na fila(???)
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
	free(aeroporto);
	return 0;
}
