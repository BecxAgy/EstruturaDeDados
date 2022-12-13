#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float raiz(int numero, int precisao)
{
    int inicio = 0, fim = numero;
    int meio;
    float raiz;
    float aumento = 0.1;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (meio * meio == numero)
        {
            raiz = meio;
            break;
        }
        if (meio * meio < numero)
        {
            inicio = meio + 1;
            raiz = meio;
        }
        else
        {
            fim = meio - 1;
        }
    }
    for (int i = 0; i < precisao; i++)
    {
        while (raiz * raiz <= numero)
        {
            raiz += aumento;
        }
        raiz = raiz - aumento;
        aumento = aumento / 10;
    }
    return raiz;
}

int main()
{
    printf("Digite um numero :");
    double numero;
    scanf("%lf", &numero);
    if (numero > 0)
    {
        printf("%lf\n", raiz(numero, 6));
    }
    else
    {
        printf("digite um numero positivo\n");
    }

    return 0;
}