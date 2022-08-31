#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*Criar programa que leia elementos de uma matriz inteira de 10x10 e escreva os elementos da diagonal principal*/
int main()
{
  int linha = 10;
  int matriz[linha][linha], i, j;
  for (i = 0; i < linha; i++)
  {
    for (j = 0; j < linha; j++)
    {
      printf("digite um num");
      scanf("%d", &matriz[i][j]);
    }
    printf("\n");
  }
  for (i = 0, j = 0; i < linha; i++, j++)
  {
    printf("%d\n", matriz[i][j]);
  }
}

