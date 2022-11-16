/*Crie um programa que dado uma string,
coloque as letras dela em ordem crescente pelo
algoritmo da bolha. */

#include <stdio.h>
#include <string.h>

void bubbleSort(char vetor[], int tamanho){
	int aux, i, j;
	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
            }
        }
    }
 
}

int main() {

  char string[100];
  
  puts("Digite uma string \n");
  fgets(string,100,stdin);

  bubbleSort(string, strlen(string));
  printf("String ordenada: %s", string);
}

