#include <stdio.h>
#include <stdlib.h>
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

 

    int resto = (n - aux)*2;
    if (resto %2==0) {
        resto++;
    }

    printf(" A posicao que josephus deverá ficar é %i", resto);
   
}