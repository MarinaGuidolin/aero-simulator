#include "fila.h"

/**
 * fila.c
 * Implementação das funções da fila.h
 * Descrições em fila.h
 **/

// fila[i] retornara um tipo elemento_t ???

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
	if(fila =! NULL)
		free(fila);
}

void inserir (fila_ordenada_t * fila, aviao_t * dado) {
	elemento_t* elemento = aloca_elemento(dado);	
	size_t combustivelInserido = dado->combustivel;	
	if(fila == NULL){ // se a fila estiver vazia, o elemento adicionado será o primeiro elemento e o ultimo elemento
		fila->primeiro = dado;
		fila->ultimo = dado;

	}
	else if{
		int i = (n_tamanho_atual_fila - 1); // começa comparando com o elemento de menor combustivel
		while(i >= 0){	
			if(fila[i]->combustivel > combustivelInserido){ // se o item da fila tiver mais combustivel do que o inserido
				dado-> proximo = fila[i]-> proximo; // o elemento seguinte ao inserido sera o seguinte ao que ele pegou o lugar 
				fila[i]->proximo = dado; // o proximo do elemento que estava na fila sera o inserido
				dado-> anterior = fila[i]; // o anterior ao elemento inserido sera o dado que ja estava na fila
				n_tamanho_atual_fila++;
				break; // para o while ??
			}
			i++;
		}
	}



}

aviao_t * remover (fila_ordenada_t * fila) {

  //elemento_t removido, auxiliar, primeiro, posterior;
  
  //auxiliar->anterior = NULL;
  //auxiliar->proximo = NULL;
  //auxiliar->dado = NULL;
  if(fila->n_tamanho_atual_fila == 0){
  	printf("Fila vazia\n"); 
  	return;

  }
  /*
  primeiro = fila->primeiro;
  removido = primeiro;
  posterior = primeiro->proximo; //primeiro->anterior (??) 
  primeiro->proximo = auxiliar; 
  posterior->anterior = auxiliar;
  auxiliar->anterior = primeiro;
  auxiliar->proximo = posterior;
  primeiro = posterior;
  primeiro->anterior = NULL;
  fila->n_tamanho_atual_fila-- ;
  desaloca_elemento(removido);
  */

  elemento_t removido = fila->primeiro; // o primeiro elemento da fila sera o removido
  elemento_t novoPrimeiro = removido->anterior; // o novo primeiro elemento da fila é o anterior ao removido
  fila->primeiro = novoPrimeiro // o novo primeiro elemento da fila sera o anterior ao removido
  novoPrimeiro->proximo = NULL;
  n_tamanho_atual_fila --;
  desaloca_elemento(removido);




  return removido;
}