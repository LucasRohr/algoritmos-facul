#include <stdio.h>

#define LINE 2
#define COLUMN 2

int main()
{
    int matrix[LINE][COLUMN];
    int arrayIndex = 0;

    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("Digite o valor na posicao [%d][%d]:\n", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (matrix[i][j] < 0)
            {
                matrix[i][j] = matrix[i][j] * -1; // Replace value with module, if negative
            }

            printf("Valor na posicao [%d][%d]: %d\n", i, j, matrix[i][j]);
        }
    }
}