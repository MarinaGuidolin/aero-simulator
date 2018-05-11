#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#include "fila.h"

/**
 * fila.c
 * Implementação das funções da fila.h
 * Descrições em fila.h
 **/

fila_ordenada_t *criar_fila() { // aloca espaço para a fila
  fila_ordenada_t* fila = (fila_ordenada_t*)malloc(sizeof(fila_ordenada_t));
  fila->primeiro = NULL;
  fila->ultimo = NULL;
  fila->n_elementos = 0;
  return fila;
}

elemento_t *aloca_elemento (aviao_t *dado) {
  elemento_t *elemento = (elemento_t*) malloc(sizeof(elemento_t*)); // aloca espaço para um elemento_t
  elemento->anterior = NULL;
  elemento->proximo = NULL;
  elemento->dado = dado;
  return elemento;
}

void desaloca_elemento (elemento_t *elemento) {
  	free(elemento);
}

void desaloca_fila (fila_ordenada_t *fila) {
	elemento_t *elemento = fila->primeiro;
	elemento_t *post;
  for (size_t i = 0; i < fila->n_elementos; i++) {
		post = elemento->proximo;
		desaloca_elemento(elemento);
		elemento = post;
	}
	free(fila);
}

void inserir (fila_ordenada_t *fila, aviao_t *dado) {
  elemento_t *elemento = aloca_elemento(dado);
  if (fila->n_elementos == 0) { // se a fila estiver vazia, o elemento adicionado será o primeiro elemento e o ultimo elemento
    fila->primeiro = elemento;
    fila->ultimo = elemento;
  } else if (dado->combustivel <= 1) {
    elemento_t *primeiro = fila->primeiro;
    primeiro->anterior = elemento;
    fila->primeiro = elemento;
  } else {
    elemento_t *ultimo = fila->ultimo;
    ultimo->proximo = elemento;
    fila->ultimo = elemento;
  }
  fila->n_elementos++;
}

aviao_t *remover (fila_ordenada_t *fila) {
  if(fila->n_elementos == 0) {
    printf("Fila vazia\n"); 
    return 0;
  }
  elemento_t* prim = fila->primeiro;
  aviao_t* removido = prim->dado;
  fila->primeiro = prim->proximo;
  fila->n_elementos--;
  desaloca_elemento(prim);
  return removido;
}
