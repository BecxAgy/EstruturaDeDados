#include <stdio.h>

int main ()
{


  int pessoasMenor21 = 0;
  int pessoasMaior50 = 0;
  int idadeAtual = 10;

  while (idadeAtual > 0)
    {
      printf ("Digite sua idade e de seus conhecidos.\n Digite valores abaixo de zero     para encerrar");
      scanf ("%i", &idadeAtual);

      if (idadeAtual > 50)
	    {
	      pessoasMaior50++;
	    }

      if (idadeAtual < 21)
	    {
	      pessoasMenor21++;
	    }

    }

  printf ("Pessoas com menos de 21 : %i \n", pessoasMenor21);
  printf ("Pessoas com mais de 50 : %i \n", pessoasMaior50);

  
}
