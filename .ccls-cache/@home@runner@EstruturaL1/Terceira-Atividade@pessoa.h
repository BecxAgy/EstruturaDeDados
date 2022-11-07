
#ifndef __PESSOA_H_
#define __PESSOA_H_

#define true 1
#define false 0

#define MAX 10 // Quantidade máxima de pessoas na lista
#define TAM_NOME 50
#define TAM_END 70
#define TAM_TEL 12

typedef struct {
  char nome[TAM_NOME];
  char endereco[TAM_END];
  char telefone[TAM_TEL]; 
} Pessoa;

// Lista de pessoar
typedef struct {
  int qtdPessoa;
  Pessoa pessoas[MAX];
} listaPessoas;

#endif //__PESSOA_H_