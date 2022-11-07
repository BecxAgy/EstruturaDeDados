#ifndef __GARAGEM_H_
#define __GARAGEM_H_

#define MAX 20 

#define TAM_PLACA 8
#define TAM_MODEL 31
#define TAM_COR 11

    

    // Estrutura que compõe um aluno
    typedef struct {
      char placa[TAM_PLACA];
      char modelo[TAM_MODEL];
      char cor[TAM_COR];
    } Carro;

    // Lista de Alunos
    typedef struct {
        int qtdCarros;
        Carro carros[MAX];
    } Garagem;

    

#endif // __GARAGEM_H_