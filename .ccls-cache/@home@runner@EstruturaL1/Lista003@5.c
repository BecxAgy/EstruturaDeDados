/*Crie um programa que dado uma string,
coloque as letras dela em ordem crescente pelo
algoritmo quick-sort. */

#include <stdio.h> 
#include <string.h>

int particiona(char *vetor, int inicio, int fim) {
  
  int esq, dir;
  char pivo, aux;
  esq = inicio;         // 0
  dir = fim;            // 4
  pivo = vetor[inicio]; // a
  while (esq < dir) {
    while (vetor[esq] <= pivo)
      esq++;
    while (vetor[dir] > pivo)
      dir--;
    if (esq < dir) {
      aux = vetor[esq];
      vetor[esq] = vetor[dir];
      vetor[dir] = aux;
    }
  }
  vetor[inicio] = vetor[dir];
  vetor[dir] = pivo;
  return dir;
}

void quickSort(char *vetor, int inicio, int fim) {
  int pivo;
  if (fim > inicio) {
    pivo = particiona(vetor, inicio, fim);
    quickSort(vetor, inicio, pivo - 1);
    quickSort(vetor, pivo + 1, fim);
  }
}

int main() {
  
  char string[100];
  puts("Digite sua string");
  fgets(string,100,stdin);

  quickSort(string,0,strlen(string)-1);

  puts(string);
}