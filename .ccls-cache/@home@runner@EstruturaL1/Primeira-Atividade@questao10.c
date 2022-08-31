#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*Criar programa que leia e armazena os elementos de uma matriz M inteira
10x10 e imprima todos os elementos que estão em linhas pares e colunas
impares.*/

int main()
{
  int linha = 10;
  int matriz[10][10], l, c;
  
  for (l = 0; l < linha; l++)
  {
    for (c = 0; c < linha; c++)
    {
      printf("digite um num");
      scanf("%d", & matriz[l][c]);
    }
    printf("\n");
  }
  for (l = 0; l < linha; l=l+2)
  {
    for (c = 1; c < linha; c=c+2)
    {
      printf("num: %d\n", matriz[l][c]);
    }
  }
  
}