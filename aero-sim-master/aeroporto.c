#include "aeroporto.h"
#include "fila.h"
#include "aviao.h"
#include "semaphore.h"
#include <stdlib.h>
#include <stdbool.h>
/**
 * aeroporto.c
 * Implementação das funções do aeroporto.h
 * Descrições em aeroporto.h
 **/
sem_t portoes, esteiras; //semafoto da pista

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
	aeroporto->fila_pousar = criar_fila();
	contador_pistas_livres = n_pistas;
	sem_init(&portoes, 0, aeroporto->n_portoes);
	sem_init(&esteiras, 0, aeroporto->n_esteiras);
	return aeroporto;
}

void aproximacao_aeroporto (aeroporto_t* aeroporto, aviao_t* aviao) {
	// local onde os avioes para pousar irão esperar
	if (fila_pousar->primeiro) {
		contador_pistas_livres--;
		
	}


}

void pousar_aviao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// quando uma pista estiver desocupada

	aviao_t *aviao = remover(aeroporto->fila_pousar);
	sleep(aeroporto->t_pouso_decolagem);
	
	acoplar_portao()
}

void acoplar_portao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// aviao se dirige até aqui apos o pouso(embarque/desembarque)
	sem_wait(&portoes);
}

void transportar_bagagens (aeroporto_t* aeroporto, aviao_t* aviao) {
	// retirar as bagagens do aviao
	sem_wait(&esteiras);
	adicionar_bagagens_esteira(aeroporto, aviao);
	sem_post(&esteiras);
	// terminou o transporte libera o portao
	sem_post(&portoes);
}

void adicionar_bagagens_esteira (aeroporto_t* aeroporto, aviao_t* aviao) {
	// tempo de retirar e adicionar bagagens no aviao
	sleep(aeroporto-> t_remover_bagagens);
	sleep(aeroporto->t_bagagens_esteira);
	sleep(aeroporto->t_inserir_bagagens);
	decolar_aviao();
}

void decolar_aviao (aeroporto_t* aeroporto, aviao_t* aviao) {
	// desocupar a pista
	sem_wait(&aeroporto->pistas);
    sleep(aeroporto->t_pouso_decolagem);
    desaloca_aviao(aviao);
	sem_post(&aeroporto->pistas);
}

int finalizar_aeroporto (aeroporto_t* aeroporto) {
	free(aeroporto);
	return 0;
}
