#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int dia;
  int mes;
  int ano;

} Data;

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

int dataValida(Data data) {
  int dia = data.dia;
  int mes = data.mes;
  int ano = data.ano;
  int datavalida = 1;

  switch (mes) {
  case 1:
    if (dia < 0 || dia > 31)
      datavalida = 0;
    break;

  case 2:
    if (ehBissexto(ano) == 1)
    {
      if (dia < 0 || dia > 29)
      {
        datavalida = 0;
      }
    }
    else if(dia < 0 || dia > 28)
    {
      datavalida = 0;
    } 
    break;

  case 3:
    if (dia < 0 || dia > 31)
      datavalida = 0;
    break;
  case 4:
    if (dia < 0 || dia > 30)
      datavalida = 0;
    break;
  case 5:
    if (dia < 0 || dia > 31)
      datavalida = 0;
    break;
  case 6:
    if (dia < 0 || dia > 30)
      datavalida = 0;
    break;
  case 7:
    if (dia < 0 || dia > 31)
      datavalida = 0;
    break;
  case 8:
    if (dia < 0 || dia > 31)
      datavalida = 0;
    break;
  case 9:
    if (dia < 0 || dia > 30)
      datavalida = 0;
    break;
  case 10:
    if (dia < 0 || dia > 31)
      datavalida = 0;
    break;
  case 11:
    if (dia < 0 || dia > 30)
      datavalida = 0;
    break;
  case 12:
    if (dia < 0 || dia > 31)
      datavalida = 0;
    break;
  }
  return datavalida;
}

int estruturaDataValida(char data[]) {
  // uma função que recebe como parâmetro uma data do tipo string (no formato
  // DD/MM/AAAA) e uma estrutura dotipo Data, onde o resultado deve ser
  // armazenado, e retorna verdadeiro se a data estiver válida; caso contrário,
  // retorna falso;
  Data dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;
  int datavalida;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sDia[i] = '\0';       // coloca o barra zero no final
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

  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sMes[i] = '\0';       // coloca o barra zero no final
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

  if (i == 4) { // 4 digitos
    sAno[i] = '\0';       // coloca o barra zero no final
  } else {
    datavalida = 0;
    return datavalida;
  }

  dq.dia = atoi(sDia);
  dq.mes = atoi(sMes);
  dq.ano = atoi(sAno);

  datavalida = 1;

  return datavalida;
}

int somaDiasData(Data data, int num){
  int totalDias;
  int qtdMes = 0;
  int mes = data.mes;
  


  //calculo de mes
  while(mes != 1){
    if( mes == 3 || mes == 5 || mes == 7|| mes ==  8 || mes == 10 || mes == 11){
      qtdMes+= 31;
    }
    if(mes == 4 || mes == 6 || mes == 5 || mes == 9|| mes == 11 ){
      qtdMes +=30;
    }
    if(mes == 2 && ehBissexto(data.ano) == 1){
      qtdMes +=29;
    }else{
      qtdMes+= 28;
    }

    mes--;
  }

  totalDias = num + data.dia + qtdMes;

  return totalDias;
}

int subtracaoDiasData(Data data, int num){
  int totalDias;
  int qtdAno = 0;
  int qtdMes = 0;
  int ano = data.ano;
  int mes = data.mes;
  int aux;

  //calculo de dias do ano
  for(int i = 0; i < data.ano - 1900; i++){
    if(ehBissexto(ano) == 1){
      qtdAno += 366;
    }else{
      qtdAno = 365;
    }
    ano--;
  }

  //calculo de mes
  while(mes != 1){
    if( mes == 3 || mes == 5 || mes == 7|| mes ==  8 || mes == 10 || mes == 11){
      qtdMes+= 31;
    }
    if(mes == 4 || mes == 6 || mes == 5 || mes == 9|| mes == 11 ){
      qtdMes +=30;
    }
    if(mes == 2 && ehBissexto(data.ano) == 1){
      qtdMes +=29;
    }else{
      qtdMes+= 28;
    }

    mes--;
  }

  totalDias = data.dia + qtdMes +qtdAno - num;

  return totalDias;
}

int dataExtenso(char data[]){
  int dia = (data[0] - '0')* 10 + (data[1] - '0');
  int mes = (data[3]-'0')*10 + (data[4] - '0');
  int ano = (data[6] - '0') *1000 + (data[7] - '0') * 100 + (data[8] - '0')*10 +(data[9] - '0');
  
  if(estruturaDataValida(data) == 1){   
    switch(mes){
      case 1:
      printf("Data: %i de Janeiro de %i",dia, ano );
      break;

      case 2:
      printf("Data: %i de Fevereiro de %i",dia, ano );
      break;

      case 3:
      printf("Data: %i de Março de %i",dia, ano );
      break;

      case 4:
      printf("Data: %i de Abril de %i",dia, ano );
      break;

      case 5:
      printf("Data: %i de Maio de %i",dia, ano );
      break;

      case 6:
      printf("Data: %i de Junho de %i",dia, ano );
      break;

      case 7:
      printf("Data: %i de Julho de %i",dia, ano );
      break;

      case 8:
      printf("Data: %i de Agosto de %i",dia, ano );
      break;

      case 9:
      printf("Data: %i de Setembro de %i",dia, ano );
      break;

      case 10:
      printf("Data: %i de Outubro de %i",dia, ano );
      break;

      case 11:
      printf("Data: %i de Novembro de %i",dia, ano );
      break;

      case 12:
      printf("Data: %i de Dezembro de %i",dia, ano );
      break;
      
    }
    return 1;
  }else{
    return 0;
  }
}

int dataPascoa(int ano){
  int a = ano%19;
  int b = ano/100; //quociente
  int c = ano%100;
  int d =  b/4;
  int e = b%4;
  int g = ( (8*b)+13)/25;
  int h = ( (19 * a) +b - d -g + 15)/30;
  int j = c / 4;
  int  k = c%4;
  int m = (a + 11*h)%319;
  int r = (2*(e+j) -k-h+m+32)%7;
  int n = (h-m+r+90)/25;
  int p = (h-m+r+n+19)%32;
  printf("dia? %i", p);
  return p;

  
  
  
  
  
}

int main(){
  char data[] = "29/01/2022";
  Data data2;

  data2.dia = 29;
  data2.mes = 1;
  data2.ano = 2022;

  printf("%i \n", dataPascoa(data2.ano));
  
  
  
}