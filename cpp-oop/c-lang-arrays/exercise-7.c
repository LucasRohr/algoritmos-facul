#include <stdio.h>

#define LINE 5
#define COLUMN 5
#define COMPARATION_VALUE 10

int main()
{
    int matrix[LINE][COLUMN];
    int comparation_value_counter = 0;

    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("Digite o valor na posicao [%d][%d]:\n", i, j);
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] > COMPARATION_VALUE)
            {
                comparation_value_counter++;
            }
        }
    }

    printf("Total de valores maiores que 10: %d\n", comparation_value_counter);
}