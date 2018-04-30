#include "aviao.h"

/**
 * aviao.c
 * Implementação das funções do aviao.h
 * Descrições em aviao.h
 **/
// cada vez que uma thread é criada, ela entra na funcao aloca_aviao e aloca um novo aviao na memoria
// o id de cada aviao é fornecido pelo numero da thread que o alocou me memoria
// numero de bagagens ????

size_t combustivel_local, id_local, bagagem_local;
// retorna um vetor chamado aviao 
aviao_t * aloca_aviao (size_t combustivel, size_t id) { // aloca aonde ??? memoria
 	
 	malloc(sizeof(size_t) *(combustivel + id)); 
 	aviao_t[0] = combustivel;
 	aviao_t[1] = id; //(????)
}

void desaloca_aviao(aviao_t* aviao) {
	free(aviao);
}
