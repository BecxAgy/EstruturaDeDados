#include <stdio.h>
#include <string.h>
#define TAM 5


void imprimeVetor(int vetorAtual[TAM]) {
  for (int i = 0; i < TAM; i++) {
    printf("%d ", vetorAtual[i]);
  }
  printf("\n");
}

int main() {
  int matriz[5][5] = {{3, 2, 5, 7, 8},
                      {1, 6, 2, 9, 5},
                      {8, 4, 1, 0, 4},
                      {2, 7, 5, 4, 9},
                      {12, 4, 2, 5, 7}};
  int vetorMaiores[5];
  int vetorMenores[5];
  int vetorDiv2[5];

  int l = 0;
  int c = 0;

  int menorAtual;
  int maiorAtual;

  while (c < 5) {
    l = 0;
    menorAtual = matriz[l][c];
    maiorAtual = matriz[l][c];

    for (int l; l < 5; l++) {

      if (matriz[l][c] < menorAtual) {
        menorAtual = matriz[l][c];
      }

      if (matriz[l][c] > maiorAtual) {
        maiorAtual = matriz[l][c];
      }
    }

    vetorMaiores[c] = maiorAtual;
    vetorMenores[c] = menorAtual;
    vetorDiv2[c] = (maiorAtual + menorAtual) / 2;

    c++;
  }

  puts("Vetor maiores :");
  imprimeVetor(vetorMaiores);
  puts("Vetor menores :");
  imprimeVetor(vetorMenores);
  puts("Vetor a+b/2");
  imprimeVetor(vetorDiv2);
}