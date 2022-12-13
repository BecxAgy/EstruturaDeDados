
#include <stdio.h>
#include <stdlib.h>
#define TAM 10;

/*exercício 1 Em algumas aplicações tem-se que trabalhar com mais de uma

pilha ao mesmo tempo. Pode-se implementar essas pilhas em um mesmo ar-
ranjo, de forma que cada uma ocupe parte desse arranjo. Faça um programa

que tenha duas pilhas alocadas em um mesmo arranjo, sendo que cada uma
delas cresce em sentido oposto. Implemente algoritmos para as seguintes
operações:
■ inicialização das duas pilhas;
■ verificar se as duas pilhas estão vazias;
■ empilhar um elemento em cada uma das pilhas;
■ desempilhar um elemento de cada uma das pilhas;
■ imprimir o conteúdo do nodo no topo das duas pilhas.*/
#define MAX 10

typedef struct {
  int *A;
  int topo1;
  int topo2;
} PILHADUPLA;

void inicia(PILHADUPLA *p) {
  p->topo1 = -1;
  p->topo2 = MAX;
}

int exibir(PILHADUPLA *p, int pilha) {
  // usuario deverá indicar se quer inserir na pilha 1 ou 2
  if (pilha < 1 || pilha > 2)
    return 0;
  printf("Pilha %i: \" ", pilha);
  int i;
  if (pilha == 1)
    for (i = p->topo1; i >= 0; i--)
      printf("%i ", p->A[i]);
  else
    for (i = p->topo2; i < MAX; i++)
      printf("%i ", p->A[i]);
  printf("\"\n");
  return 1;
}

int vazia(PILHADUPLA *p, int pilha) {
  if (pilha < 1 || pilha > 2)
    return 0;
  if (pilha == 1) {
    if (p->topo1 == -1) // vazia?
      return 1;

  } else {
    if (p->topo2 == MAX) // vazia?
      return 1;
  }
  return 0;
}

int empilhar(PILHADUPLA *p, int reg, int pilha) {
  if (pilha < 1 || pilha > 2)
    return 0;
  if (p->topo1 + 1 == p->topo2) //cheia?
    return 0;
  if (pilha == 1) {
    p->topo1 = p->topo1 + 1;
    p->A[p->topo1] = reg;
  } else {
    p->topo2 = p->topo2 - 1;
    p->A[p->topo2] = reg;
  }
  return 1;
}

int desempilhar(PILHADUPLA *p, int pilha) {
  if (pilha < 1 || pilha > 2)
    return 0;
  
  if (p->topo1 == -1) {
      printf("Está vazia...");
      return 0;
  
    p->topo1--;
    
  }else {
     
    if (p->topo2 == MAX) // vazia?
      printf("Está vazia...");
      return 0;
    
    p->topo2++;;
   }
  
  return 1;
}

int menu(void) {
  int opt;

  printf("Escolha a opcao\n");
  printf("0. Sair\n");
  printf("1. Exibir PILHA\n");
  printf("2. PUSH\n");
  printf("3. POP\n");

  printf("Opcao: ");
  scanf("%d", &opt);

  return opt;
}

void opcao(PILHADUPLA *PILHA, int op) {
  int p;
 
  int valor;

  
  puts("Em qual pilha deseja operar?");
  scanf("%i", &p);
  
  switch (op) {
  case 0:

    break;

  case 1:
    exibir(PILHA, p);
    break;

  case 2:
    puts("Qual valor deseja inserir");
    scanf("%i",&valor);
    
    empilhar(PILHA, valor, p);
    break;

  case 3:
     desempilhar(PILHA,p);
    break;


  default:
    printf("Comando invalido\n\n");
  }
}


int main(void)
{
 PILHADUPLA PILHA;
PILHA.A = (int*) malloc(sizeof(int));
  
 if(!PILHA.A){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(&PILHA);
 int opt;

 do{
  opt=menu();
  opcao(&PILHA,opt);
 }while(opt);

 free(PILHA.A);
 return 0;
 }
}
