#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int conteudo;
  struct No *prox;
} No;

typedef struct {
  No *elemento;
  int tam;
} Lista;

void inserirInicio(Lista *lista, int valor) {
  No *novo = (No *)malloc(sizeof(No));
  // construir o elemento para inserir na lista
  novo->conteudo = valor;
  novo->prox = NULL;
  // adicionando nó na lista
  lista->elemento = novo;
  lista->tam++;
}

void inserirFim(Lista *lista, int valor) {
  No *novo = (No *)malloc(sizeof(No));
  No *noAux;
  novo->conteudo = valor;
  novo->prox = NULL;
  // Verificando se há elementos no inicio da lista
  if (lista->elemento == NULL) {
    lista->elemento = novo;
  } else {
    // adicionando no final da lista
    noAux = lista->elemento;
    while (noAux->prox != NULL)
      noAux = noAux->prox;

    noAux->prox = novo;
  }

  lista->tam++;
}

void imprime(Lista *lista) {
  No *no = lista->elemento;

  while (no->prox != NULL) {
    printf("%d ", no->conteudo);
    no = no->prox;
  }
}

void remover(Lista *lista, int valor) {
  No *inicio = lista->elemento;
  No *noARemover = NULL;

  // se for o primeiro elemento e a lista não estiver vazia
  if (inicio != NULL) {
    if (lista->elemento->conteudo == valor) {
      noARemover = lista->elemento;
      lista->elemento = noARemover->prox;
    } else {
      while (inicio->prox != NULL && inicio->prox->conteudo == valor) {
        inicio = inicio->prox;
      }

      if (inicio != NULL && inicio->prox != NULL) {
        noARemover = inicio->prox;
        inicio->prox = noARemover->prox;
      }
    }
  }
  if (noARemover) {
    free(noARemover);
    lista->tam--;
  }
}
