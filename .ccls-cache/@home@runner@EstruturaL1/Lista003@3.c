/*Faça um programa que leia n lista e
ordene-os pelo tamanho utilizando o algoritmo
da seleção. No final, o algoritmo deve mostrar
todos os lista ordenados. */

#include <stdio.h>
#include <string.h>

typedef struct{
  char nome[100];
}Nome;

int selectionSort(int n, Nome lista[]) {
  int i, j;
  int menor = 0;
  Nome auxnome;
  
  for (i = 0; i < n - 1; i++) {
    menor = i;
    for (j = i + 1; j < n; j++) {
      if (lista[j].nome[0] < lista[menor].nome[0]) {
        menor = j;
      }
    }
    strcpy(auxnome.nome , lista[i].nome);
    strcpy(lista[i].nome , lista[menor].nome);
    strcpy(lista[menor].nome , auxnome.nome);
  }
}




int main() {
  int n ;

  
  puts("Digite quantos deseja inserir na lista");
  scanf("%d", &n);
  getchar();
  
  Nome lista[n];

  for(int i = 0; i<n;i++) {
    puts("Digite o nome");
    fgets(lista[i].nome,100,stdin);
  }

  for( int j = 0; j<n; j++) {
    selectionSort(n, lista);
    puts(lista[j].nome);
  }

  
}