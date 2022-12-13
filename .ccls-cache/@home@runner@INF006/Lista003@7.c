#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*7 – Considere a seguinte estrutura:
typedef struct _pessoa_ {
unsigned int Matricula;
float Nota;
} Aluno;
Faça uma função que, dado um valor inteiro N
positivo, aloque dinamicamente um vetor de
Aluno, leia do teclado os N pares de valores
(Matricula, Nota) e retorne o vetor alocado.
Imprima, ao final do programa, duas listas: (1)
alunos ordenados por nota final e (2) alunos
ordenados por número de matrícula. Utilize
algoritmos de ordenação vistos em aula e
justifique as suas escolhas.
*/


typedef struct{
  int matricula;
  float nota; 
}Aluno;

Aluno* alocaN(Aluno *lista, int n){

  int nMatric;
  float nota;

  lista = (Aluno*) calloc(n, sizeof(Aluno));

  for(int i=0; i < n; i++){
    printf("\nGerando matricula...");
    nMatric = 2022+(i*5);
    printf("\n Digite a nota do aluno:");
    scanf("%f", &nota);

    (lista + i)->matricula = nMatric;
    (lista + i) -> nota = nota;
    
  }


  return lista;
}

//Irei utilizar o insertion pois minha entrada não será muito grande.
void insertionSort(Aluno *arr, int size){
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = (arr + i) ->nota;
        j = i - 1;
        while (j >= 0 && (arr + j) ->nota > key) {
            *(arr + (j + 1)) = *(arr + j);
           
            j = j - 1;
        }
        (arr + (j+1)) ->nota= key;
    }
}

void selecao (Aluno *vet, int tam){
		int i, j, min;
    Aluno *x;
		for (i=1; i<=tam-1; i++){
				min = i;
				for (j=i+1; j<=tam; j++){
					if ((vet + j)->matricula < (vet + min)->matricula)
							min = j;
					}
		x =  (vet + min);
		*(vet + min) = *(vet + i);
		*(vet + i) = *x;
		}
}

void listarpNota(Aluno *lista, int n){

  insertionSort(lista, n);
  puts("====== Listagem por nota ======");
  for(int i = 0; i < n; i++){
    printf("Matricula: %i\n",(lista + i) ->matricula);
    printf("Nota: %f\n", (lista + i) ->nota);
  }
  
}

void listarpMatric(Aluno *lista, int n){

  selecao(lista, n);
  puts("====== Listagem por Matrícula ======");
  for(int i = 0; i < n; i++){
    printf("Matricula: %i\n",(lista + i) ->matricula);
    printf("Nota: %f\n", (lista + i) ->nota);
  }
  
}

int main(){
  Aluno *lista;
  int n, escolha;
  printf("Quantos alunos você deseja inserir?");
  scanf("%i", &n);
  
  lista = alocaN(lista,n);

  puts("Você deseja listar os alunos por...\n[1]-Nota\n[2]-Matricula\n ");
  scanf("%i", &escolha);
  if(escolha ==1) listarpNota(lista, n);

  if(escolha==2) listarpMatric(lista,n);

  free(lista);
  
}