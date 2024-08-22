#include <stdio.h>

#define TAM_MAX 10

int count_negatives(int array[TAM_MAX])
{
    int counter = 0;

    for (int i = 0; i < TAM_MAX; i++)
    {
        if (array[i] < 0)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    int array[TAM_MAX] = {-1, 2, 3, 67, -23, 0, -3, 5, 9, -8};
    int count = count_negatives(array);

    printf("Negatives count = %d", count);
}