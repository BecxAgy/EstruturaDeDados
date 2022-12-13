#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
  int n;
    puts("Insira a quantidade de soldados.");
    scanf("%i", &n);

  
  
    int qntdSoldados = n;
    int aux = 2;
    int cont = 1;
    
    while(aux*2<qntdSoldados) {
        aux = aux*2;
        cont ++;
    }


    printf("aux = %i\n", aux);

    int resto = 41 - aux;

    if (res)
    printf("%i \n", aux);
}