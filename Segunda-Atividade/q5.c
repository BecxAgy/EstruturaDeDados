#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main()
{
  int n = 10;
  int linha, coluna;
  int matriz[n][n];
  for (linha = 0; linha < n; linha++)
  {
    for (coluna = 0; coluna < n; coluna++)
    {
      scanf("%d", &matriz[linha][coluna]);
    }
  }
  for (linha = 0, coluna = 0; linha < n; linha++, coluna++)
  {
    if (linha + 1 < 4)
    {
      printf("%d\n", matriz[linha + 1][coluna]);
    }
  }
}
