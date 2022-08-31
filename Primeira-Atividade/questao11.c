#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int matriz[10][10];
  

  for(int linha = 0; linha < 10; linha++){
    for(int coluna = 0; coluna < 10; coluna++){
      scanf("%i", &matriz[linha][coluna]);
    }
  }

  for(int i = 9; i <= 0; i--){
    for(int j = 9; j <= 0; i-- ){
      printf("%i", matriz[i][j]);
    }
  }
}