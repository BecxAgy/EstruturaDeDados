
#include <stdio.h>
#define TAM 5

int main() {

  int matriz[TAM][TAM];

  for (int l = 0; l < TAM; l++) {
    for (int c = 0; c < TAM; c++) {
      printf("Digite o valor da linha %i, coluna %i\n", l, c);
      scanf("%i", &matriz[l][c]);
    }
  }

  int ehTriang = 0;
  int limiteColuna = 1;
  for (int l = 1; l < TAM; l++) {
    if (limiteColuna <= TAM - 1) {
      for (int c = 0; c < limiteColuna; c++) {
        if (matriz[l][c] != 0) {
          ehTriang = -1;
        }
      }

      limiteColuna++;
    }
  }
  if (ehTriang < 0) {
    puts("Não é triangular superior");
  } else {
    puts("É triangular superior");
  }
}