#include "fila.h"

/**
 * fila.c
 * Implementação das funções da fila.h
 * Descrições em fila.h
 **/

fila_ordenada_t * criar_fila (size_t n_avioes) { // aloca espaço para a fila
	fila_ordenada_t fila;
	fila = (fila_ordenada_t*)malloc(sizeof(fila_ordenada_t));
	fila->primeiro = NULL;
	fila->ultimo = NULL; 
	fila->n_elementos = n_avioes; // fila possui um tamanho maximo de n avioes
	fila->n_tamanho_atual_fila = 0; // fila iniciada com zero elementos
    return fila;
}

 elemento_t * aloca_elemento (aviao_t * dado) {
    elemento_t elemento*;
    elemento = (elemento_t*)malloc(sizeof(elemento_t*)); // aloca espaço para um elemento_t
    // como definir o .elemento_t *anterior e *proximo??
    elemento->dado = dado;
    return elemento;

 }

 void desaloca_elemento (elemento_t * elemento) {
 	free(elemento);
 }



void desaloca_fila (fila_ordenada_t * fila) {
	if(fila == NULL)
		free(fila);
}

void inserir (fila_ordenada_t * fila, aviao_t * dado) {
	elemento_t* elemento = aloca_elemento(dado);
	aviao_t novoDado = elemento->dado;
	size_t combustivelInserido = novoDado->combustivel;
	int combustivelDoPrimeiro = fila->primeiro->combustivel; // combustivel do primeiro elemento
	if(fila == NULL){
		fila->primeiro = dado;
		fila->ultimo = dado;
	}
	else if(combustivelInserido < combustivelDoPrimeiro)
		novoDado->anterior = fila->primeiro; // o elemento anterior ao dado será o que era o primeiro
		fila->primeiro = novoDado;






}

aviao_t * remover (fila_ordenada_t * fila) {

  elemento_t removido, auxiliar, primeiro, posterior;
  
  auxiliar->anterior = NULL;
  auxiliar->proximo = NULL;
  auxiliar->dado = NULL;
  if(fila->n_tamanho_atual_fila == 0){
  	printf("Fila vazia\n"); 
  	return;

  }
  primeiro = fila->primeiro;
  posterior = primeiro->proximo;
  primeiro->proximo = auxiliar;
  posterior->anterior = auxiliar;
  auxiliar->anterior = primeiro;
  auxiliar->proximo = posterior;
  removido = primeiro;
  primeiro = posterior;
  primeiro->anterior = NULL;
  fila->n_tamanho_atual_fila-- ;
  desaloca_elemento(removido);

  return removido;
}