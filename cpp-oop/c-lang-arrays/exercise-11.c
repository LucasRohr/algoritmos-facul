#include <stdio.h>

#define LINE 6
#define COLUMN 5
#define TAM_ANSWERS 5

int main()
{
    char matrix[LINE][COLUMN];
    char answers[TAM_ANSWERS];
    int scores[LINE] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("Digite a resposta do aluno %d para a questao %d:\n", i + 1, j + 1);
            scanf(" %c", &matrix[i][j]);
            getchar();
        }
    }

    for (int i = 0; i < TAM_ANSWERS; i++)
    {
        printf("Digite a resposta do gabarito para a questao %d:\n", i + 1);
        scanf(" %c", &answers[i]);
        getchar();
    }

    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (matrix[i][j] == answers[j])
            {
                scores[i] += 2;
            }
        }
    }

    printf("Pontuacao final dos alunos: \n\n");

    for (int i = 0; i < LINE; i++)
    {
        printf("Aluno %d - Nota: %d\n", i + 1, scores[i]);
    }
}