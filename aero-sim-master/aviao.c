#include "aviao.h"
#include <pthread.h>

/**
 * aviao.c
 * Implementação das funções do aviao.h
 * Descrições em aviao.h
 **/
// cada vez que uma thread é criada, ela entra na funcao aloca_aviao e aloca um novo aviao na memoria
// o id de cada aviao é fornecido pelo numero da thread que o alocou me memoria


// retorna um vetor chamado aviao 
void *aloca_aviao (size_t combustivel, size_t id)) { 
	aviao_t aviao = *(aviao_t*) argument; 	
 	aviao = (aviao_t * ) malloc(sizeof(aviao_t));
 	
 	
}

void desaloca_aviao(aviao_t* aviao) {
	free(aviao);
}