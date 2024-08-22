#include <stdio.h>

#define TAM_MAX 10

void main()
{
    float array[TAM_MAX];

    for (int i = 0; i < TAM_MAX; i++)
    {
        printf("Digite o valor %d:\n", i + 1);
        scanf("%f", &array[i]);
    }

    printf("\n\nArray:\n");

    for (int i = 0; i < TAM_MAX; i++)
    {
        printf("%.2f ", array[i]);
    }
}