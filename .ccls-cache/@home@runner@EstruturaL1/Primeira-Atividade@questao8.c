
#include <stdio.h>
#define MAX 20

int main () {
 
    int elementos[MAX];
    int eleMaior, eleMenor;
    int quantPares = 0;
    int somaTotal = 0;
    
    for (int i =0;i<MAX;i++) {
        printf("Digite o valor da posição %i \n", i);
        scanf("%i", &elementos[i]);
        
        somaTotal+= elementos[i];
        
        if(elementos[i]%2==0) {
            quantPares++;
        }

    }
    
    eleMaior = elementos[0];
    eleMenor = elementos[0];
    
    for (int j = 0; j<MAX; j++) {
        if(elementos[j]<eleMenor) {
            eleMenor = elementos[j];
        }
        
        if(elementos[j]>eleMaior) {
            eleMaior = elementos[j];
        }
    }
    
    
    float media = somaTotal/MAX;
    float percentPares = quantPares/MAX;
    
    
    printf("Maior valor : %i \n",eleMaior);

    printf("Menor valor : %i \n",eleMenor);

    printf("Percentual de pares : %f \n ", percentPares);

    printf("Média dos elementos: %f \n",media);
}
