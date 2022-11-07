#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

listaClientes *criaLista() {
  listaClientes *list;

  list = (listaClientes *)malloc(sizeof(listaClientes));

  if (list != NULL) {

    list->qtdClientes = 0;
  }

  return list;
}

int ehBissexto(int ano) {
  int bis;

  if (ano % 4 == 0 && !(ano % 100 == 0))
    bis = 1;
  else if (ano % 4 == 0 && (ano % 100 == 0 && ano % 400 == 0))
    bis = 1;
  else
    bis = 0;

  return bis;
}

int estruturaDataValida(char data[]) {
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;
  int datavalida;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  if (i == 2) {
    sDia[i] = '\0'; // coloca o barra zero no final
  } else {
    datavalida = 0;
    return datavalida;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++) {
    sMes[i] = data[j];
    i++;
  }

  if (i == 2) {     // testa se tem 1 ou dois digitos
    sMes[i] = '\0'; // coloca o barra zero no final
  } else {
    datavalida = 0;
    return datavalida;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++) {
    sAno[i] = data[j];
    i++;
  }

  if (i == 4) {     // 4 digitos
    sAno[i] = '\0'; // coloca o barra zero no final
  } else {
    datavalida = 0;
    return datavalida;
  }

  datavalida = 1;

  return datavalida;
}

int validaNome(char nome[]) {
  int valido = 0;

  for (int i = 0; nome[i] != '\0'; i++) {
    if ((nome[i] >= 'a' && nome[i] <= 'z') ||
        (nome[i] >= 'A' && nome[i] <= 'Z') || nome[i] == ' ') {
      valido = 1;
    } else {
      valido = 0;
      break;
    }
  }
  return valido;
}

void rendaValida(float renda) {
  int valida = 1;
  if (renda <= 0) {
    puts("Infelimente não é possível se cadastrar com essa renda...");
    valida = 0;
  }
}

void mostraErros(int erros[2]) {
  if (erros[0] == 0) {
    puts("Nome inválido...");
  }
  if (erros[1] == 0) {
    puts("Data inválida");
  }
}

void tratarNome(char nome[], listaClientes *lista) {
  char auxNome[100] = {0};
  int tamAuxNome;

  // Tratando o nome (retirando espaços excedentes)
  char *pNome = strtok(nome, " ");
  while (pNome != NULL) {
    strcat(auxNome, pNome);
    strcat(auxNome, " ");
    pNome = strtok(NULL, " ");
  }

  tamAuxNome = strlen(auxNome) - 1;
  auxNome[tamAuxNome] = '\0'; // Removendo o espaço final extra
  strcpy(lista->clientes[lista->qtdClientes].nome,
         auxNome); // Colocando o nome tratado na lista
}

void Cadastro(listaClientes *list) {
  Cliente cliente;
  int confirmaCad = 1;
  int erros[3];

  do {

    puts("-=-=-=- Sessão Cadastro =-=-=-=- \n");
    puts("Informe seu nome completo");

    scanf("%[^\n]", cliente.nome);
    getchar();
    erros[0] = validaNome(cliente.nome);

    puts("Insira a data de nascimento no formato DD/MM/AAAA");
    scanf("%[^\n]", cliente.data);
    getchar();
    erros[1] = estruturaDataValida(cliente.data);

    puts("Insira sua renda:");
    scanf("%f", &cliente.renda);
    rendaValida(cliente.renda);

    if (erros[0] == 1 && erros[0] == 1) {
      list->clientes[list->qtdClientes] = cliente;
      tratarNome(cliente.nome, list);
      list->qtdClientes++;
      puts("\nCliente Cadastrado com Sucesso!\n");
      confirmaCad = 0;
      break;
    } else {
      puts("\nNão foi possível cadastrar esse novo cliente..\n");
      mostraErros(erros);
      confirmaCad = 1;
    }
  } while (confirmaCad == 1);
}

void Listar(listaClientes *list) {
  int i;
  if (list->qtdClientes == 0) {
    puts("Não existe clientes cadastrados...");
  } else {
    for (i = 0; i < list->qtdClientes; i++) {
      puts("-----------------------------");
      printf("Nome: %s\n", list->clientes[i].nome);
      printf("Data de Nascimento:%s\n", list->clientes[i].data);
      printf("Renda mensal: R$%2.f\n", list->clientes[i].renda);
    }
  }
}

void Excluir(listaClientes *list) {
  if (list == NULL)
    puts("Impossível executar. A lista não existe!");
  else {
    int opcao;
    do {
      puts("Escolha:");
      puts("[ 1 ] Nome  [ 2 ] Cancelar Operação");
      printf("Opção: ");
      scanf("%d", &opcao);

      if (opcao < 1 || opcao > 2)
        puts("Opção Inválida. Tente novamente!");
    } while (opcao < 1 || opcao > 2);

    switch (opcao) {
    case 1: {
      char nome[100];
      int confirmacaoDel = 1;
      int i = 0;
      int erro = 0;

      while (confirmacaoDel == 1) {
        getchar();
        printf("Digite o nome do Cliente: ");
        scanf("%[^\n]", nome);

        while (i < list->qtdClientes &&
               strcmp(list->clientes[i].nome, nome) != 0)
          i++;
        if (i == list->qtdClientes) {
          puts("\nCliente não encontrado!");

          erro = 1;
        }
        if (erro == 0) {

          for (int j = i; j < list->qtdClientes; j++) {
            list->clientes[j] = list->clientes[j + 1];
          }
          list->qtdClientes--;
          puts("Cliente Removido com sucesso!");
          confirmacaoDel = 0;
        }
      }
    }
    }
  }
}

void Listar1980a2000(listaClientes *list) {
  if (list->qtdClientes == 0) {
    puts("Não existe clientes cadastrados...");
  } else {
    int ano;
    int mil;
    int cent;
    int dez;
    int uni;
    int existe = 0;

    for (int i = 0; i < list->qtdClientes; i++) {
      mil = (list->clientes[i].data[6] - '0') * 1000;
      cent = (list->clientes[i].data[7] - '0') * 100;
      dez = (list->clientes[i].data[8] - '0') * 10;
      uni = (list->clientes[i].data[9] - '0');
      ano = mil + cent + dez + uni;
      printf("%i\n\n", ano);
      if ((ano >= 1980 && ano <= 2000)) {
        puts("-----------------------------");
        printf("Nome: %s\n", list->clientes[i].nome);
        printf("Data de Nascimento:%s\n", list->clientes[i].data);
        printf("Renda mensal: R$%2.f\n", list->clientes[i].renda);
        existe = 1;
      }
    }
    if (existe == 0) {
      puts("Não existem clientes com esses criterios...");
    }
  }
}

void CalculaRendaAcima(listaClientes *list){
  
}

int main() {

  listaClientes *list;
  list = criaLista();
  int opcao = 0;

  do {
    puts("=-=-=-=- :) -=-=-=-=-=");
    puts("O que deseja fazer:\n[1] - Cadastrar Cliente\n[2] - Listar "
         "Clientes\n[3] - Remover Cliente\n[4] - Clientes nascidos entre 1980 "
         "e 2000\n[5] - Sair");
    scanf("%i", &opcao);
    getchar();
    switch (opcao) {
    case 1:
      Cadastro(list);
      break;
    case 2:
      Listar(list);
      break;
    case 3:
      Excluir(
          list); // não excluir pelo nome, mas espero que considere a lógica...
      break;

    case 4:
      Listar1980a2000(list);
      break;

    default:
      printf("Saindo...\n\n");
      opcao = 0;
      break;
    }

  } while (opcao != 0);
  puts("XXXXXX FIM DO PROGRAMA XXXXXX");
}
