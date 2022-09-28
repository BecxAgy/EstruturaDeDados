#include <stdio.h>
#define TAM 5

/*Que  entre com dados num vetor VET do tipo inteiro com 20 oisiçoes, onde podem
 * existir varios elementos repetidos. Gere um vetor VET1 que tambem será
 * ordenado e terá somente os elementos do vetor VET que não sao repetidos.*/

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
  int i, j, cont;
  int k = 0;

  int vet[n], vet2[n];

  for (i = 0; i < n; i++) {
    printf("Digite um valor\n");
    scanf("%d", &vet[i]);
  }
  for (i = 0; i < n; i++) {
    cont = 0;
    for (j = 0; j < n; j++) {
      if (i != j && vet[i] == vet[j]) {
        cont++;
      }
    }
    if (cont == 0) {
      vet2[k] = vet[i];
      k++;
    }
  }
  ordenaSort(vet2, k);
  
  for (i = 0; i < k; i++) {
    printf("%d ", vet2[i]);
  }
}
