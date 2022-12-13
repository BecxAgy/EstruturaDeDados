
#include <stdio.h>
#define MAX 10

#include <stdio.h>
#include <stdlib.h>

struct No{
 int placa;
 struct No *prox;
};
typedef struct No node;

int tam;

int menu(void);
void inicia(node *PILHA);
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void libera(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA, int posicaoCarro);


int main(void)
{
 node *PILHA = (node *) malloc(sizeof(node));
 if(!PILHA){
  printf("Estacionamento fechado!\n");
  exit(1);
 }else{
 inicia(PILHA);
 int opt;

 do{
  opt=menu();
  opcao(PILHA,opt);
 }while(opt);

 free(PILHA);
 return 0;
 }
}

void inicia(node *PILHA)
{
 PILHA->prox = NULL;
 tam=0;
}

int menu(void)
{
 int opt;

 printf("Escolha a opcao\n");
 printf("0. Sair\n");
 printf("1. Retirar todos os carros\n");
 printf("2. Exibir carros estacionados\n");
 printf("3. Estacionar um carro (PUSH)\n");
 printf("4. Retirar um carro (POP)\n");
 printf("Opcao: "); scanf("%d", &opt);

 return opt;
}

void opcao(node *PILHA, int op)
{
 node *tmp;
  int posicao;
 switch(op){
  case 0:
   libera(PILHA);
   break;

  case 1:
   libera(PILHA);
   inicia(PILHA);
   break;

  case 2:
   exibe(PILHA);
   break;

  case 3:
   
   push(PILHA);
   break;

  case 4:
    printf("Em que posição o carro que deseja retirar está?");
    scanf("%i", &posicao);
   tmp= pop(PILHA,posicao);
   if(tmp != NULL)
   printf("Retirado: %3d\n\n", tmp->placa);
   break;

  default:
   printf("Comando invalido\n\n");
 }
}

int vazia(node *PILHA)
{
 if(PILHA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(tam>=10){
      printf("Estacionamento cheio");
      }   
 if(!novo){
  printf("Estacionamento fechado!\n");
  
  exit(1);
 }else{
  printf("Novo carro:(int) "); scanf("%d", &novo->placa);
  return novo;
 }
}


void exibe(node *PILHA)
{
 if(vazia(PILHA)){
  printf("Estacionamento vazio!\n\n");
  return ;
 }

 node *tmp;
 tmp = PILHA->prox;
 printf("Estacionados:");
 while( tmp != NULL){
  printf("%5d", tmp->placa);
  tmp = tmp->prox;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);


 printf("\n\n");
}

void libera(node *PILHA)
{
 if(!vazia(PILHA)){
  node *proxNode,
     *atual;

  atual = PILHA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}

void push(node *PILHA)
{
 node *novo=aloca();
 novo->prox = NULL;

 if(vazia(PILHA))
  PILHA->prox=novo;
 else{
  node *tmp = PILHA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}


node *pop(node *PILHA, int placaCarro)
{
  node *inicio = PILHA;
  node *noARemover = NULL;

  // se for o primeiro elemento e a lista não estiver vazia
  if (inicio != NULL) {
    if (PILHA->placa == placaCarro) {
      noARemover = PILHA;
      PILHA = noARemover->prox;
    } else {
      while (inicio->prox != NULL && inicio->placa == placaCarro) {
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
    
  }
}