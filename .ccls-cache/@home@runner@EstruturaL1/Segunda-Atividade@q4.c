#include <stdio.h>
#define TAM 10

void ordenaSort(int vetor[], int n) {

  int menor;
  int aux;

  for (int i = 0; i < n - 1; i++) { // n - 1
    menor = i;

    for (int j = i + 1; j < n; j++) { // n
      if (vetor[j] > vetor[menor]) {
        menor = j;
      }
      aux = vetor[i];
      vetor[i] = vetor[menor];
      vetor[menor] = aux;
    }
  }
}

int main() {
  int n = TAM;
  int aux = 0;

  int vet[n],

  for (int i = 0; i < n; i++) {
    printf("Digite um valor\n");
    scanf("%d", &vet[i]);
  }

  ordenaSort(vet, n);

  for (int j = 0 ; j < TAM; j++) {

    printf("[%d", vet[j]);
    printf("]");
  }
}