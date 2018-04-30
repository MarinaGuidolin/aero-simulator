#include "fila.h"

/**
 * fila.c
 * Implementação das funções da fila.h
 * Descrições em fila.h
 **/
fila_ordenada_t * criar_fila (size_t n_avioes) { // aloca espaço para a fila
	fila_ordenada_t fila;
	fila = (fila_ordenada_t*)malloc(sizeof(fila_ordenada_t));
    return fila;
}

 elemento_t * aloca_elemento (aviao_t * dado) {
    elemento_t elemento*;
    elemento = (elemento_t*)malloc(sizeof(elemento_t*)); // aloca espaço para um elemento_t
    // como definir o .elemento_t *anterior e *proximo??
    elemento.dado = dado;
    return elemento;

 }

 void desaloca_elemento (elemento_t * elemento) {
 	free(elemento);
 }



void desaloca_fila (fila_ordenada_t * fila) {
	free(fila);
}

void inserir (fila_ordenada_t * fila, aviao_t * dado) {

}

aviao_t * remover (fila_ordenada_t * fila) {
  return NULL;
}
