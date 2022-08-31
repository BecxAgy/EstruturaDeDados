#include <stdio.h>
/*Armazenar nomes e nota 1, 2, de 15 alunos. calcular e armazenar a media.
armazenar tambem a situação do aluno: AP ou RP. imprimir uma listagem
contendo nome, notas, media e a situação de cada aluno.*/

typedef struct aluno{
  char nome[31];
  float nota1;
  float nota2;
  float media;
  int aprovado;
}Aluno[15];


int main(){
  Aluno aluno1;
  float media;

  for(int i = 0; i < 15; i++){

    printf("Qual seu nome:");
    fgets(aluno1[i].nome, 31, stdin);

    printf("Digite sua primeira nota \n");
    scanf("%f", &aluno1[i].nota1);

    printf("Digite a segunda nota \n");
    scanf("%f", &aluno1[i].nota2);

    aluno1[i].media = (aluno1[i].nota1 + aluno1[i].nota2)/2;
    media = aluno1[i].media;
    
    if(media >= 5){
      aluno1[i].aprovado = 1;
        
    }else{
      aluno1[i].aprovado = 0;
    }
    
    printf("Nome:");
    puts(aluno1[i].nome);

    printf("Notas: 1 - %f \n 2 - %f \n",aluno1[i].nota1, aluno1[i].nota2);
    printf("Média: %f \n ", media);
    if(aluno1[i].aprovado == 1){
      printf("Situação: AP");
    }else{
      printf("Situação: RP");
    }
    
  }
}