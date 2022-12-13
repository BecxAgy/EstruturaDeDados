#ifndef __EMPRESA1_H_
#define __EMPRESA1_H_

#define true 1
#define false 0

#define MAX 20 // Quantidade máxima de pessoas na lista
#define TAM_NOME 50
#define TAM_DATA 11
#define TAM_END 70
#define TAM_TEL 12



typedef struct {
  int cod;
  char nome[TAM_NOME];
  char endereco[TAM_END];
  char telefone[TAM_TEL];
  char dataCompra[TAM_DATA];
  
} Cliente;


typedef struct {
  int qtdClientes;
  Cliente clientes[MAX];
} listaClientes;

#endif //__EMPRESA1_H_