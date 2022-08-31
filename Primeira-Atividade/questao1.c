#include <stdio.h>

int main()
{
    float massa ;
    
    printf("Digite a massa:\n ");
    scanf("%f", &massa);
    
    int tempo = 0;
    
    while (massa > 0.1) {
        tempo +=30;
        massa -= (massa * 0.25);
    }
    
    printf("%i", tempo);

}
