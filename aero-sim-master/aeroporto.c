#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "aeroporto.h"
#include "fila.h"
#include "aviao.h"
#include "semaphore.h"

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
	aeroporto->fila_pistas = criar_fila(); // fila antes de entrar na pista
	sem_init(&portoes, 0, aeroporto->n_portoes); // semaforo que define os portoes ocupados 
	sem_init(&esteiras, 0, aeroporto->n_esteiras); // semaforo que define as esteiras ocupadas
	sem_init(&pistas, 0, aeroporto->n_pistas); // semaforo que define as pistas ocupadas
	sem_init(&fila, 0, 1); // semaforo que define a fila
	return aeroporto;
}

void aproximacao_aeroporto (aeroporto_t* aeroporto, aviao_t* aviao) {
	// local onde os avioes para pousar irão esperar
	sem_wait(&fila); // verifica se estao inserindo na fila
	inserir(aeroporto->fila_pistas, aviao);
	printf("Aviao %d inserido na fila com %d de combustivel\n", aviao->id, aviao->combustivel);
	sem_post(&fila); // libera o semaforo de inserir na fila
	pousar_aviao(aeroporto, aviao); // semaforo da pista é liberado apenas após sua saida da pista
}

void pousar_aviao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// quando uma pista estiver desocupada
	sem_wait(&pistas); // verifica se a pista esta ocupada
	aviao_t *aviao = remover(aeroporto->fila_pousar); // tira o aviao da fila de pouso --> "pousa o aviao"
	printf("Aviao %d pousou\n", aviao->id);
	sleep(aeroporto->t_pouso_decolagem); // "tempo de pouso"
	sem_post(&pistas); // libera uma pista
	acoplar_portao(aeroporto, aviao); // se aproxima para acoplar ao portao
}

void acoplar_portao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// aviao se dirige até aqui apos o pouso(embarque/desembarque)
	sem_wait(&portoes); // espera um portao estar liberado
	printf("Aviao %d acoplado no portao", aviao->id);
	sem_post(&portoes); // libera um portao
	transportar_bagagens(aeroporto, aviao);
	
}

void transportar_bagagens (aeroporto_t* aeroporto, aviao_t* aviao) {
	// retirar as bagagens do aviao
	sem_wait(&esteiras); // espera por uma esteira livre
	printf("Aviao %d adicionando bagagens na esteira\n", aviao->id);
	adicionar_bagagens_esteira(aeroporto, aviao);
	sem_post(&esteiras); // libera uma esteira
	// terminou o transporte libera o portao
	sem_post(&portoes);
}

void adicionar_bagagens_esteira (aeroporto_t* aeroporto, aviao_t* aviao) {
	sleep(t_remover_bagagens);
	sleep(t_bagagens_esteira);
	sleep(t_inserir_bagagens);		
}

void decolar_aviao (aeroporto_t* aeroporto, aviao_t* aviao) {
	sem_wait(&pistas); // verifica se a pista esta ocupada
	printf("Aviao %d decolando.\n", aviao->id);
    sleep(aeroporto->t_pouso_decolagem);
    desaloca_aviao(aviao);
	sem_post(&aeroporto->pistas); // libera a pista
}

int finalizar_aeroporto (aeroporto_t* aeroporto) {
	free(aeroporto);
	return 0;
}
