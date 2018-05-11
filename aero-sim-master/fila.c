#include "fila.h"
#include <stdlib.h>
#include    <stdio.h>
#include <stdlib.h>
/**
 * fila.c
 * Implementação das funções da fila.h
 * Descrições em fila.h
 **/

 elemento_t * aloca_elemento (aviao_t * dado) {
    
    elemento_t* elemento = (elemento_t*) malloc(sizeof(elemento_t));
    
    elemento->anterior = NULL;
    elemento->proximo = NULL;
    elemento->dado = dado;

    return elemento;
 }

 void desaloca_elemento (elemento_t * elemento) {
    free(elemento);
 }

fila_ordenada_t * criar_fila () {
    printf("antes de alocar fila no criar fila\n");
    fila_ordenada_t* fila = (fila_ordenada_t*) malloc(sizeof(fila_ordenada_t));
    printf("fila criada no criarfila\n");

    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->n_elementos = 0;
    printf("apos definir vetores fila\n");
    return fila;
    
}


void desaloca_fila (fila_ordenada_t * fila) {
  elemento_t* elemento = fila->primeiro;
  for (size_t i = 0; i < fila->n_elementos; i++) {
    elemento_t *proximo = elemento->proximo;
    free(elemento);
    elemento = proximo;
  }
  
  free(fila);
}

void inserir (fila_ordenada_t *fila, aviao_t *dado) {
  elemento_t* elemento = aloca_elemento(dado);  
  size_t combustivel_aviao_a_inserir = dado->combustivel; 

  if (fila->n_elementos == 0) { // se a fila estiver vazia, o elemento adicionado será o primeiro elemento e o ultimo elemento
    fila->primeiro = elemento;
    fila->ultimo = elemento;
  } else if (combustivel_aviao_a_inserir == 1) {
        elemento_t *primeiro = fila->primeiro;
        primeiro->anterior = elemento;
        fila->primeiro = elemento;
    } else {
        elemento_t *ultimo = fila->ultimo;
        ultimo->proximo = elemento;
        fila->ultimo = elemento;
    }
    
}

aviao_t *remover (fila_ordenada_t * fila) {
  if(fila->n_elementos == 0) {
      printf("Fila vazia\n"); 
      return;
    }
    elemento_t* prim = fila->primeiro;
    aviao_t* removido = prim->dado;
    fila->primeiro = prim->proximo;
    fila->n_elementos--;
    desaloca_elemento(prim);
    return removido;
}
