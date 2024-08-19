// Programa de revisao para a primeira prova do semestre

#include <stdio.h>
#include <math.h>

#define CHAR 'r';

int main() {
    // Declaracao de variavel

    int valor = 0;
    float nota; // Nota da prova 1 de um aluno
    char caractere = CHAR;

    // Print e Leitura de dados

    printf("=\tDigite o valor\t=\n");
    scanf("%d", &valor);

    printf("=\tDigite a nota\t=\n");
    scanf("%f", &nota);

    fflush(stdin);

    // printf("=\tDigite o char\t=\n");
    // scanf("%c", &caractere);

    printf("Dados: %d - %7.2f - %c\n\n", valor, nota, caractere);

    // Operacoes

    printf("Quadrado do valor: %d\n\n", (int) pow(valor, 2));

    printf("Media ponderada: %.3f\n\n", (float) ((valor * 1) + (nota * 2)) / 3);

    return 0;
}