
#ifndef __EMPRESA_H_
#define __EMPRESA_H_

#define true 1
#define false 0

#define MAX 20 // Quantidade máxima de pessoas na lista
#define TAM_NOME 50
#define TAM_DATA 11



typedef struct {
  char nome[TAM_NOME];
  char data[TAM_DATA];
  float renda; 
} Cliente;


typedef struct {
  int qtdClientes;
  Cliente clientes[MAX];
} listaClientes;

#endif //__EMPRESA_H_