#include <stdio.h>

#define LINE 6
#define COLUMN 6

int main()
{
    int matrix[LINE][COLUMN];
    int array[LINE * COLUMN];
    int valueA;
    int arrayIndex = 0;

    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("Digite o valor na posicao [%d][%d]:\n", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Digite o valor A: \n");
    scanf("%d", &valueA);

    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            array[arrayIndex] = matrix[i][j] * valueA;
            arrayIndex++;
        }
    }

    printf("\nVetor V resultante: \n\n");

    for (int i = 0; i < arrayIndex; i++)
    {
        printf("%d ", array[i]);
    }
}