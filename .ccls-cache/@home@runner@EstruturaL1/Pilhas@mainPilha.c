#include <stdio.h>
#include <string.h>
#include "pilhadechars.c"


/*Protótipos de funções principais*/


int ler_opcao(){
  int op;

  printf("O que deseja fazer:\n[1] - Empilhar\n[2] - Desempilhar\n[3]-Imprimir\n[4]-Sair");

  printf("Entre com a opção desejada:");
  scanf("%i", &op);

  return op;
}
int main(){
  pilha *p;
  int opcao;
  char value;

  criaPilha(p);

  while(!4){
    opcao = ler_opcao();
    
    switch(opcao){
      case 1:
       
        printf("Entre com o valor que deseja");
        scanf("%c", &value);
        
        empilha(p, value);
        break;
      case 2:
        desempilha(p);
        break;

      case 3:
        imprimir(*p);
        break;

      default:
       printf("Finalizando...");
        opcao = 4;
      
    }
  }
}
