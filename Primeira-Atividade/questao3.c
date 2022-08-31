#include <stdio.h>

int main ()
{
    int populacaoA = 5000000;
    int populacaoB = 7000000;
    float taxaA = 0.03;
    float taxaB = 0.02;
    int tempoAnos = 0;
    
    
    while (populacaoB>+populacaoA) {
        populacaoA += (populacaoA*taxaA);
        populacaoB += (populacaoB*taxaB);
        tempoAnos++;
    }
    
    
    printf("As população A vai ultrapassar a populacaoB em %i anos", tempoAnos); 

}
