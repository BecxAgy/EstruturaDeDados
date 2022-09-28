#include <stdio.h>

int main(){

  int vetor[8] = {3,1,4,7,2,6,8,5};
  int menor;
  int aux;

  for(int i = 0; i < 7; ){//n - 1
    menor = i;

    for(int j = i +1; j < 8; j++){ // n
      if(vetor[j] > vetor[menor]){
        menor = j;
      }
      aux = vetor[i];
      vetor[i] = vetor[menor];
      vetor[j] = aux;
    }
  }
    
    
}
//Algoritimo de Seleção - Quadrático ----> n^2 - n

/*
Trocas: (n - 1)
Comparações : n^2


Algoritimos que tem menores trocas, são melhores sendo rodados no disco, pois o tempo de escrita é menor
Em quesito de comparação ele é o mesmo que usar o da bolha
Soma = n/2 * (n-1)

Exemplo: Vetor com 10 mil posições 

(10000 * 9999)/2  

Trocas: bolha: 250000
selecao: 9999


*/