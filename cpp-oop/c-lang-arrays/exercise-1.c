#include <stdio.h>

#define TAM_MAX 11

int main()
{
    int array[TAM_MAX];

    for (int i = 0; i < TAM_MAX - 1; i++)
    {
        array[i] = TAM_MAX - 1 - i;
    }

    printf("Array 1:\n");

    for (int i = 0; i < TAM_MAX - 1; i++)
    {
        printf("%d ", array[i]);
    }

    for (int i = 0; i <= TAM_MAX; i++)
    {
        array[i] = i * i;
    }

    printf("\n\nArray 2:\n");

    for (int i = 0; i < TAM_MAX; i++)
    {
        printf("%d ", array[i]);
    }

    for (int i = 0; i < TAM_MAX - 6; i++)
    {
        array[i] = i + 1;
        array[i + 5] = (i + 1) * 10;
    }

    printf("\n\nArray 3:\n");

    for (int i = 0; i < TAM_MAX - 1; i++)
    {
        printf("%d ", array[i]);
    }
}