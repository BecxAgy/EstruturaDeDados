#include <stdio.h>
#define MAX 256
#define L 76
#define S 76

int main () {
 
    char nome[MAX];
    char nomes[MAX];
    int contNomes = 0;
    int contNome = 0;
    int idade;
    
    
 
    for(int i =0 ; i<20; i++) {
        
        printf("Digite seu nome \n");
        fgets(nome,MAX, stdin); 
    
        printf("Digite a idade \n");
        scanf("%i", &idade);
        getchar(); 
         
        if (nome[0]>=L && nome[0] <=S) 
        {
            
            for(contNome=0;nome[contNome]!='\0';contNome++) {
                nomes[contNomes] = nome[contNome];
                contNomes++;
            }
          
        }
    }
     
    printf("==== NOMES [L-S] === \n");
     
    for(int j = 0; j<contNomes; j++) {
        printf("%c", nomes[j]);
    }    
   
}
