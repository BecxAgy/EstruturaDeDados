#include <stdio.h>

/*Criar programa que leia dois conjuntos de números inteiros, tendo cada
um 10 e 20 elementos e apresente os elementos comuns aos conjuntos.
lembre-se de que os elementos podem se repetir mas não podem aparecer
repetidos na saída*/

int main() 
{

  int conjunto1[10];
  int conjunto2[20];
  int intersec[10];
  int contador = 0;
  

  // primeira leitura

  printf("Insira 10 valores\n");

  for (int i = 0; i < 10; i++) {

    scanf("%i", &conjunto1[i]);
  }

  printf("Insira 20 valores");

  for (int k = 0; k < 20; k++) {
    scanf("%i", &conjunto2[k]);
  }

  //{1,2,5,4,1,3,2,4,6,10}
  //{4,2,5,1,29,3,4,12,32,1,4,1,4,5,9,3,5,3,3,1}

    for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (conjunto1[j] == conjunto2[i] && conjunto1[i] != intersec[i]) {
        intersec[contador] = conjunto1[j];
        contador++;
      }
    }
  }
  for (int n = 0; n < contador; n++) {
    if (intersec[n] != intersec[n - 1])
      printf("%d\n", intersec[n]);
  }
}
