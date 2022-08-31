#include <stdio.h>

int main(){
  int
main ()
{
    float altChico = 1.5;
    float altJuca = 1.1;
    float taxaChico = 0.02;
    float taxaJuca = 0.03;
    int tempoAnos = 0;
    
    
    while (altJuca<=altChico) {
        altChico += taxaChico;
        altJuca += taxaJuca;
        tempoAnos++;
    }
    
    
    printf("Juca será maior que Chico em  %i anos \n %f --- %f", tempoAnos, altChico, altJuca); 

}

}