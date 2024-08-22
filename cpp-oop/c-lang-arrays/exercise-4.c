#include <stdio.h>

#define TAM_MAX 10

int count_occurrences(int array[TAM_MAX], int value)
{
    int counter = 0;

    for (int i = 0; i < TAM_MAX; i++)
    {
        if (array[i] == value)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    int array[TAM_MAX];
    int value;
    int count;

    for (int i = 0; i < TAM_MAX; i++)
    {
        printf("Digite o valor %d do vetor:\n", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\n\nDigite o valor a ser encontrado:\n");
    scanf("%d", &value);

    count = count_occurrences(array, value);

    printf("\nTotal de ocorrencias de %d no vetor = %d", value, count);
}