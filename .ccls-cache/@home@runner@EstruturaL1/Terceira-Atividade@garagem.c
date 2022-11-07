#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "garagem.h"

Garagem* criaGaragem(){
  Garagem *garagem;

    garagem = (Garagem *) malloc(sizeof (Garagem));

    if (garagem != NULL) {
        
        garagem -> qtdCarros = 0;
    }
   
    return garagem;
}

int validaPlaca(char placa[]){
  //combinacao de 4 letras e 3 numeros ABC3D21
  int valido = 0;

  if((placa[0] >= 'A' && placa[0] <= 'Z') && (placa[1] >= 'A' && placa[1] <= 'Z') && (placa[2] >= 'A' && placa[2] <= 'Z')){
    
    if(placa[3]>='0' && placa[3] <= '9'){
      
      if((placa[4] >= 'A' && placa[4] <= 'Z')){
        
        if((placa[5]>='0' && placa[5] <= '9') && placa[6]>='0' && placa[6] <= '9'){
          valido = 1;
        }
      
      }
    }
  }
  
  return valido;
}

int validaCor(char cor[]){
  int valido = 1;
  for(int i = 0; cor[i] != '\0'; i++){
    if(!(cor[i] >='A' && cor[i] <= 'Z') && !(cor[i]>='a' && cor[i]<='z')){
     valido = 0;
   }
  } 
  return valido;
}

void mostraErro(int erros[2]){
  if(erros[0] == 0){
    printf("Placa inválida.\n");
  }
  
  if(erros[1] == 0){
    printf("Cor inserida é inválida.\n");
  }

}

void Cadastrar(Garagem *list){
  Carro carro;
  int confirmaCad = 1;
  int erros[2];//validações

  if(list -> qtdCarros == MAX){
    puts("A lista encontra-se cheia. Tente mais tarde!");
  }
  
  do{
    getchar();
    puts("-=-=-=- Entrada de Carros =-=-=-=- \n");
    puts("Informe a placa do carro =- Ex: AAA1B23");
    scanf("%s", carro.placa);
    getchar();
    erros[0] = validaPlaca(carro.placa);
    
    puts("Qual a Cor do Carro?");
    scanf("%s", carro.cor);
    getchar();
    erros[1] = validaCor(carro.cor);
    
    puts("Insira seu modelo de carro:");
    scanf("%s", carro.modelo);
    getchar();
  
  
    if(erros[0] == 1 && erros[0] == 1){
      list -> carros[list -> qtdCarros] = carro;
      list -> qtdCarros++;
     puts("\nCadastrado com Sucesso!\n");
      confirmaCad = 0;
      break;
    } else {
      puts("\nNão foi possível cadastrar...\n");
      mostraErro(erros);
      confirmaCad = 1;
    }  
  }while(confirmaCad == 1);
  
}

void Listar(Garagem *list){
  int i;
  if(list -> qtdCarros == 0 ){
    puts("O estacionamento está vazio...");  
  }else{
    for(i = 0; i < list -> qtdCarros; i++){
      puts("-----------------------------");
      printf("Placa: %s\n", list -> carros[i].placa);
      printf("Cor:%s\n", list -> carros[i].cor);
      printf("Modelo: %s\n", list -> carros[i].modelo);
    }
    
  }
}

void Excluir(Garagem *list){
  if(list -> qtdCarros == 0){
    puts("Não existem carros para serem retirados do sistema!");
  }else{
    int confirmaDel = 0;
    char placa[8];
    int i = 0;
    int erro = 0;
    
    do{
      puts("==-=-==-=-=-==-=-==");
      puts("Digite a placa do carro que deseja retirar do sistema...");
      scanf("%s", placa);

      while(i < list -> qtdCarros && strcmp(list -> carros[i].placa, placa) != 0){
        i++;
        if(i == list -> qtdCarros){
          puts("O carro não pode ser encontrado...");
          erro = 1;
        }
      }
        if(erro == 0){
          //removendo
          for (int j = i; j < list -> qtdCarros - 1; j++) {
            list -> carros[j] = list -> carros[j + 1];
          }
          list -> qtdCarros--;
          puts("\nCarro Removido com Sucesso!"); 
          confirmaDel = 1;
        }
        
    }while(confirmaDel == 0);
    

    
      
        }
  }
    
int main(){
  Garagem *garagem;
  garagem = criaGaragem();
  int opcao = 0;
  
  do{
  puts("=-=-=-=- Gerenciamento da Garagem -=-=-=-=-=");
  puts("O que deseja fazer:\n[1] - Inserir Carro\n[2] - Listar Carros\n[3] - Remover Carro\n[4] - Sair");
      scanf("%i", &opcao);
      getchar();
      switch(opcao){
        case 1:
          
          Cadastrar(garagem);
          break;
        case 2:
        Listar(garagem);
          break;
        case 3:
         Excluir(garagem);
          break; 
        default:
        printf("Saindo...\n\n");
        opcao=0;
        break;
        }
    

}while(opcao != 0);
  puts("XXXXXX FIM DO PROGRAMA XXXXXX");
}