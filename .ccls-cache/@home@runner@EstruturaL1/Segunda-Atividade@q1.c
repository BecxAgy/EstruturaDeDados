#include <stdio.h>

/*1) Que imprima o horóscopo de varias pessoas, a aprtir da sua data de
nascimento (ddmm). O fim é determinado quando se digita 9999 para data.
considera que a data foi digitada corretamente.

01-20 Capricornio
02-19 Aquario
03-20 Peixes
04-20 Aries
05-20 Touro
06-20 Gemeos
07-21 Cancer
08-22 Leão
09-22 Virgem
10-22 Libra
11-21 Escorpião
12-21   Sargitario */

void imprimeSigno(int mes, int dia) {
  int terminacoes[12] = {20, 19, 20, 20, 20, 20, 21, 22, 22, 22, 21, 21};
  if (dia < terminacoes[mes - 1]) {
    switch (mes) {
    case 1:
      printf("Capricornio\n");
      break;

    case 2:
      printf("Aquário\n");
      break;

    case 3:
      printf("Peixes\n");
      break;

    case 4:
      printf("Áries\n");
      break;

    case 5:
      printf("Touro\n");
      break;

    case 6:
      printf("Gemeos\n");
      break;

    case 7:
      printf("Cancer\n");
      break;

    case 8:
      printf("Leão\n");
      break;

    case 9:
      printf("Virgem\n");
      break;

    case 10:
      printf("Libra\n");
      break;

    case 11:
      printf("Escorpião\n");
      break;

    case 12:
      printf("Sargtário\n");
      break;
    }
  } else {
    switch (mes) {

    case 1:
      printf("Aquário\n");
      break;

    case 2:
      printf("Peixes\n");
      break;

    case 3:
      printf("Áries\n ");
      break;

    case 4:
      printf("Touro \n");
      break;

    case 5:
      printf("Gemeos \n");
      break;

    case 6:
      printf("Cancer \n");
      break;

    case 7:
      printf("Leão \n");
      break;

    case 8:
      printf("Virgem \n");
      break;

    case 9:
      printf("Libra \n");
      break;

    case 10:
      printf("Escorpião \n");
      break;

    case 11:
      printf("Sargtário \n");
      break;

    case 12:
      printf("Capricornio \n");
      break;
    }
  }
  }
  int main() {

    int ddmm = 0;
    int dia;
    int mes;

    while (ddmm != 9999) {
      printf("Digita seu nascimento no formato DDMM \n");
      scanf("%i", &ddmm);

      mes = ddmm % 100;
      dia = ddmm / 100;

   
  
    imprimeSigno(mes, dia);
    }
    
}   
