#include <stdio.h>

#define LINE 2
#define COLUMN 2

int main()
{
    int matrix[LINE][COLUMN];
    int value;

    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("Digite o valor na posicao [%d][%d]:\n", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Digite o valor a ser encontrado: \n");
    scanf("%d", &value);

    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (matrix[i][j] == value)
            {
                printf("Valor encontrado na posicao [%d][%d]\n", i, j);
                return 0;
            }
        }
    }

    printf("Valor não encontrado");
}