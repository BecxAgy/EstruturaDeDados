#include <stdio.h>
#include <string.h>

/*Refaça as funções de busca sequencial e
busca binária assumindo que o vetor possui
chaves que podem ocorrer múltiplas vezes no
vetor. Neste caso, você deve retornar, em um
outro vetor, todas as posições onde a chave foi
encontrada. Protótipo:
int busca(int vet[], int n, int chave, int
posicoes[]);
Sua função deve retornar o número de
ocorrências da chave no vetor e, para cada uma
destas ocorrências, indicar no vetor
posicoes[], as posições de vet que possuem
a chave.*/

int buscaSeq(int vet[], int n, int chave, int *posicoes) {
  int pos = 0;
  int ocorrencias = 0;
  for (int i = 0; i < n; i++) {
    if (vet[i] == chave) {
      ocorrencias++;
      *(posicoes + pos) = i;
      pos++;
    }
  }
  return ocorrencias;
}

int buscaBin(int vet[], int n, int chave, int *posicoes) {
  int inicio = 0;
  int fim = n - 1;
  int meio;
  int pos = 0;
  int ocorrencias = 0;

  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (chave == vet[meio]) {
      ocorrencias++;
      *(posicoes + pos) = meio;
      pos++;
    }
    if (chave < vet[meio]) {
      fim = meio - 1;
    } else {
      inicio = meio + 1;
    }
  }

  return ocorrencias;
}

int main() {
  int tam = 10;
  int vetor[] = {1, 2, 3, 13, 13, 18, 19, 23, 79, 79};
  int key;
  int posi[tam];
  int qtdOcorre;
  puts("Insira o elemento que deseja buscar");
  scanf("%i", &key);

  qtdOcorre = buscaBin(vetor, tam, key, posi);
  // qtdOcorre = buscaSeq(vetor, tam, key, posi);

  for (int i = 0; i < qtdOcorre; i++) {
    printf("Posição: %i\n", posi[i]);
  }
}