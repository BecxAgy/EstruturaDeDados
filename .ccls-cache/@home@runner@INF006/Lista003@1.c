#include <stdio.h>
/* 1 – Faça um programa que leia n nomes
inserindo-os em uma lista de forma ordenada
utilizando a ideia do algoritmo da inserção. No
final, o programa deve mostrar todos os nomes
ordenados alfabeticamente. */

typedef struct{
  char nome[100];
} Nome;


void insertionSort(char arr[], int n){
    int i, j;
    char key;
  
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main () {

  int n ;
  
  puts("Digite quantos nomes deseja inserir");
  scanf("%d", &n);
  getchar();
  
  Nome lista[n];

  for(int i = 0; i<n;i++) {
    puts("Digite o nome");
    fgets(lista[i].nome,100,stdin);
  }

  for( int j = 0; j<n; j++) {
    insertionSort(lista[j].nome, n);
    puts(lista[j].nome);
  }

  
}