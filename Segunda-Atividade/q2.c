#include <stdio.h>

/*2) Que dado dois vetores de 10 posições, efetue operações basicas aritmeticas, indicadas por um terceiro vetor cujos dados tambem são fornecidos pelo usuario, gerando e imprimindo um quarto vetor.*/

int main(){
  float vetor1[10];
  float vetor2[10];

  char operacao[11];

  float resultados[10];

  for(int i = 0; i < 10; i++){
    printf("Insira o valor do primeiro vetor \n");
    scanf("%f", &vetor1[i]);
    
    printf("Insira o valor do segundo vetor \n");
    scanf("%f", &vetor2[i]);

    printf("Insira a operação que deseja realizar \n");
    printf("+ -> Somar\n - -> Subtrair\n / -> Dividir\n * -> Multiplicar\n");
    
    scanf("%s", &operacao[i]);
    getchar();

    
    if(operacao[i] == '+'){
      resultados[i] = vetor1[i]+vetor2[i];
      
    }else if( operacao[i] == '-'){
      resultados[i] = vetor1[i]-vetor2[i];
      
    }else if(operacao[i] == '/'){
      resultados[i] = vetor1[i]/vetor2[i];
      
    }else if(operacao[i] == '*'){
      resultados[i] = vetor1[i]*vetor2[i];
    }
    

    printf("Resultado %i: %f \n", i+1, resultados[i]);
    

    
  }

  
}