#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "aeroporto.h"
#include "fila.h"
#include "aviao.h"
#include "semaphore.h"

/**
 * aeroporto.c
 * Implementação das funções do aeroporto.h
 * Descrições em aeroporto.h
 **/
sem_t pistas, esteiras, portoes, fila; //semafoto da pista
 
aeroporto_t* iniciar_aeroporto (size_t* args, size_t n_args) {
	aeroporto_t *aeroporto;
	aeroporto = (aeroporto_t*)malloc(sizeof(aeroporto_t));

	aeroporto->n_pistas = args[0];
	aeroporto->n_portoes = args[1];
	aeroporto->n_esteiras = args[2];
	aeroporto->n_max_avioes_esteira = args[3];
	aeroporto->t_pouso_decolagem = args[4];
	aeroporto->t_remover_bagagens= args[5];
	aeroporto->t_inserir_bagagens = args[6];
	aeroporto->t_bagagens_esteira = args[7];

	aeroporto->mutex_fila_add = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	aeroporto->mutex_fila_rm = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));

	aeroporto->sem_portoes = (sem_t*) malloc(sizeof(sem_t));
	aeroporto->sem_esteiras = (sem_t*) malloc(sizeof(sem_t));
	aeroporto->sem_pistas = (sem_t*) malloc(sizeof(sem_t));

	printf("antes da fila ser criada no aeroporto\n");
	aeroporto->fila_pouso = criar_fila(); // fila antes de entrar na pista
	printf("fila criada no aeroporto\n");

	sem_init(&sem_portoes, 0, aeroporto->n_portoes); // semaforo que define os portoes ocupados 
	sem_init(&sem_esteiras, 0, aeroporto->n_esteiras); // semaforo que define as esteiras ocupadas
	sem_init(&sem_pistas, 0, aeroporto->n_pistas); // semaforo que define as pistas ocupad

	pthread_mutex_init(&aeroporto->mutex_fila_add, NULL);
	pthread_mutex_init(&aeroporto->mutex_fila_rm, NULL);

	
	return aeroporto;
}

void aproximacao_aeroporto (void* parametros) {
	parametros_t *param = (parametros_t*) parametros;
	aeroporto_t *aeroporto = param->aeroporto;
	aviao_t *aviao = param->aviao;
	// local onde os avioes para pousar irão esperar
	pthread_mutex_lock(&aeroporto->mutex_fila_add);
	inserir(aeroporto->fila_pouso, aviao);
	pthread_mutex_unlock(&aeroporto->mutex_fila_add);
	printf("apos o unlock da fila add\n");
	pousar_aviao(aeroporto, aviao); // semaforo da pista é liberado apenas após sua saida da pista
}

void pousar_aviao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// quando uma pista estiver desocupada
	printf("começou pousar aviao, antes do semaforo de pistas\n");
	sem_wait(&aeroporto->sem_pistas); // verifica se a pista esta ocupada
	pthread_mutex_lock(&aeroporto->mutex_fila_rm);
	aviao = remover(aeroporto->fila_pouso);
	pthread_mutex_unlock(&aeroporto->mutex_fila_rm); // tira o aviao da fila de pouso --> "pousa o aviao"
	printf("Aviao %lu pousou\n", aviao->id);
	sleep(aeroporto->t_pouso_decolagem); // "tempo de pouso"
	sem_post(&aeroporto->sem_pistas); // libera uma pista
	acoplar_portao(aeroporto, aviao); // se aproxima para acoplar ao portao
}

void acoplar_portao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// aviao se dirige até aqui apos o pouso(embarque/desembarque)
	sem_wait(&aeroporto->sem_portoes); // espera um portao estar liberado
	printf("Aviao %lu acoplado no portao", aviao->id);
	sem_post(&aeroporto->sem_portoes); // libera um portao
	transportar_bagagens(aeroporto, aviao);
	
}

void transportar_bagagens (aeroporto_t* aeroporto, aviao_t* aviao) {
	// retirar as bagagens do aviao
	sem_wait(&aeroporto->sem_esteiras); // espera por uma esteira livre
	printf("Aviao %lu adicionando bagagens na esteira\n", aviao->id);
	adicionar_bagagens_esteira(aeroporto, aviao);
	sem_post(&aeroporto->sem_esteiras); // libera uma esteira
	// terminou o transporte libera o portao
	sem_post(&aeroporto->sem_portoes);
}

void adicionar_bagagens_esteira (aeroporto_t* aeroporto, aviao_t* aviao) {
	sleep(aeroporto->t_remover_bagagens);
	sleep(aeroporto->t_bagagens_esteira);
	sleep(aeroporto->t_inserir_bagagens);		
}

void decolar_aviao (aeroporto_t* aeroporto, aviao_t* aviao) {
	sem_wait(&aeroporto->sem_pistas); // verifica se a pista esta ocupada
	printf("Aviao %lu decolando.\n", aviao->id);
    sleep(aeroporto->t_pouso_decolagem);
    desaloca_aviao(aviao);
	sem_post(&aeroporto->sem_pistas); // libera a pista
}

int finalizar_aeroporto (aeroporto_t* aeroporto) {
	pthread_mutex_destroy(&aeroporto->mutex_fila_rm);
	pthread_mutex_destroy(&aeroporto->mutex_fila_add);
	sem_destroy(&aeroporto->sem_pistas);
	sem_destroy(&aeroporto->sem_esteiras);
	sem_destroy(&aeroporto->sem_portoes);
	free(aeroporto);
	return 0;
}
