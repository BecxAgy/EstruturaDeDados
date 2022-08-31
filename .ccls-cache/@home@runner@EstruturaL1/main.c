#include <stdio.h>

/*Criar programa que leia dois conjuntos de números inteiros, tendo cada
um 10 e 20 elementos e apresente os elementos comuns aos conjuntos.
lembre-se de que os elementos podem se repetir mas não podem aparecer
repetidos na saída*/

int main(){

  int conjunto1[10];
  int conjunto2[20];
  int intersec[10];
  int contador = 0;

  //primeira leitura 

  printf("Insira 10 valores\n");
  
  for(int i = 0; i < 10; i++){
    
    scanf("%i", &conjunto1[i]);
  }

  printf("Insira 20 valores" );

  for(int i = 0; i < 20; i++){
    scanf("%i", &conjunto2[i]);
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 20; j++){
      for(int k = 0; k < i; k++){
        if(conjunto1[i] == conjunto2[j]{
          if(intersec[i] != conjunto[k+1]){
            intersec[i] = conjunto1[i];
            contador++;
          }
        }
      } 
  }

  while(contador > 0) {
    printf("vetor %i \n",intersec[contador]);
    contador--;
  }

  //percorrer lista comparando os valores do vetor 1 com o 2
  

}