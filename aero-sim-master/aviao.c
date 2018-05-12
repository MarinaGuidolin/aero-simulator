#include <pthread.h>
#include <stdlib.h>

#include "aviao.h"
#include "aeroporto.h"

/**
 * aviao.c
 * Implementação das funções do aviao.h
 * Descrições em aviao.h
 **/
// cada vez que uma thread é criada, ela entra na funcao aloca_aviao e aloca um novo aviao na memoria
// o id de cada aviao é fornecido pelo numero da thread que o alocou me memoria


// retorna um vetor chamado aviao 
aviao_t *aloca_aviao (size_t combustivel, size_t id) {  	
 	aviao_t *aviao = (aviao_t *) malloc(sizeof(aviao_t));
 	aviao->combustivel = combustivel;
 	aviao->id = id;
 	return aviao;
}

void desaloca_aviao(aviao_t* aviao) {
	free(aviao);
}

void *pega_valores_aproximacao(void *arg) {
	parametros_t *param = (parametros_t*)arg;
	aproximacao_aeroporto(param->aeroporto, param->aviao);
	free(arg);
}