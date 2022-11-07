#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pessoa.h"

listaPessoas* criaLista(){
  listaPessoas *list;

    list = (listaPessoas *) malloc(sizeof (listaPessoas));

    if (list != NULL) {
        
        list -> qtdPessoa = 0;
    }
   
    return list;
}

int validaNome(char nome[]){
  int valido = 0;

  for(int i = 0; nome[i] != '\0'; i++)
  {
     if ((nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || nome[i] == ' ') {
        valido = 1; 
      }else{
       valido = 0;
       break;
      }
  }
  return valido;
}

void removeQuebraLinha(char string[]){
   size_t ln = strlen(string) - 1; 
  
        if(string[ln] == '\n') string[ln] = '\0';
}

int validaEndereco(char endereco[]){
  int valido = 0;

  for(int i = 0; endereco[i] != '\0'; i++){
    if((endereco[i] >= 'a' && endereco[i] <= 'z') && (endereco[i] >= 'A' && endereco[i] <= 'Z') && endereco[i] == ' ' || endereco[i] == ','){
      valido = 1;
    }
  }
  return valido;
}

int validaTelefone(char tel[]) {
  int valido = 0;
  // se tem 11 numeros e se existe letras
  size_t ln = strlen(tel);
  
  if (ln == TAM_TEL - 1) {

    if(tel[2] == '9' && tel[0] != '0'){
      for(int i = 0; tel[i] != '\0'; i++)
      {
        if(tel[i] >= '0' && tel[i] <= '9'){
          valido = 1;
        }
        
      }
    }
  }
  
  return valido;
}

void mostraErro(int erros[3]){
  if(erros[0] == 0){
    printf("Nome inválido.\n");
  }
  
  if(erros[1] == 0){
    printf("Endereço inserido é inválido.\n");
  }
  if(erros[2] == 0){
    printf("Telefone inserido é inválido.\n");
  }
}

void Cadastrar(listaPessoas *list){
  Pessoa pessoa;
  int confirmaCad = 1;
  int erros[3];//validações de nome, endereço, telefone

  if(list -> qtdPessoa == 10){
    puts("A lista encontra-se cheia. Tente mais tarde!");
  }

  do{
    
    puts("-=-=-=- Sessão Cadastro =-=-=-=- \n");
    puts("Informe seu nome completo");
    //nome
    
    fgets(pessoa.nome, TAM_NOME, stdin);
    removeQuebraLinha(pessoa.nome);
    erros[0] = validaNome(pessoa.nome);

  
    //endereço
    puts("Insira seu endereço");
    fgets(pessoa.endereco,  TAM_END, stdin);
    removeQuebraLinha(pessoa.endereco);
    erros[1] = validaEndereco(pessoa.endereco);
    
    //telefone
    puts("Insira seu telefone:");
    fgets(pessoa.telefone, TAM_TEL, stdin);
    removeQuebraLinha(pessoa.telefone);
    erros[2] = validaTelefone(pessoa.telefone);
  
  
    if(erros[0] == 1 && erros[0] == 1 && erros[2] == 1){
      list -> pessoas[list -> qtdPessoa] = pessoa;
      list -> qtdPessoa++;
     puts("\nPessoa Cadastrada com Sucesso!\n");
      confirmaCad = 0;
      break;
    } else {
      puts("\nNão foi possível cadastrar essa pessoa...\n");
      mostraErro(erros);
      confirmaCad = 1;
    }  
  }while(confirmaCad == 1);
}

void Listar(listaPessoas *list){
  int i;
  if(list -> qtdPessoa == 0){
    puts("Não existe pessoas... Você está só");  
  }else{
    for(i = 0; i < list -> qtdPessoa; i++){
      puts("-----------------------------");
      printf("Nome: %s\n", list -> pessoas[i].nome);
      printf("Endereço:%s\n", list -> pessoas[i].endereco);
      printf("Telefone: %s\n", list -> pessoas[i].telefone);
    }
    
  }
}

void Excluir(listaPessoas *list){
  if(list -> qtdPessoa == 0 || list == NULL){
    puts("A lista não existe ou não há pessoas nela");
  }
  else {
        int opcao;
        do {
            puts("Escolha por qual opção você deseja excluir:");
            puts(" [ 1 ] Telefone [ 2] Cancelar Operação");
            printf("Opção: ");
            scanf("%d", &opcao);

            if (opcao < 1 || opcao > 2)
                puts("Opção Inválida. Tente novamente!");
        } while (opcao < 1 || opcao > 2);

        switch (opcao) {
  
        case 1:{
                char telefone[12];
                int confirmacaoDel = 1;
                int i = 0;
                int erro = 0;

                while (confirmacaoDel == 1) {
                    printf("Digite o telefone da pessoa: ");
                    scanf("%s", telefone);
                    while (i < list -> qtdPessoa && strcmp(list -> pessoas[i].telefone, telefone) != 0)
                        i++;
                    if (i == list -> qtdPessoa) {
                        puts("\nNão encontrado!");
                        confirmacaoDel = 0;
                        erro = 1;
                    } else { confirmacaoDel = 0; }
                }

                if (erro == 0) {
                  
                    // Removendo
                    for (int j = i; j < list -> qtdPessoa - 1; j++) {
                        list -> pessoas[j] = list -> pessoas[j + 1];
                    }
                    list -> qtdPessoa--;
                    puts("\nRemovido com Sucesso!");
                }
            } break;
              
        default: puts("\nOperação Cancelada!");
        }
    
      }
    }
  
int main(){
  listaPessoas *lista;
  lista = criaLista();
  int opcao = 0;
  
  
    do{
  puts("=-=-=-=- Olá Pessoa -=-=-=-=-=");
  puts("O que deseja fazer:\n[1] - Cadastrar Pessoa\n[2] - Listar Pessoas\n[3] - Excluir Pessoa\n[4] - Sair");
      scanf("%i", &opcao);
      getchar();
      switch(opcao){
        case 1:
          
          Cadastrar(lista);
          break;
        case 2:
          Listar(lista);
          break;
        case 3:
         Excluir(lista);
          break; 
        default:
        printf("Saindo...\n\n");
        opcao=0;
        break;
        
      
      }
    }while(opcao != 0);
    puts("XXXXXX FIM DO PROGRAMA XXXXXX");

  
  
}