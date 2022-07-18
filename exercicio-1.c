#include <time.h> // Biblioteca necessária para random
#include <stdlib.h>
#include<stdio.h>
#define TAM 10
#define TAM_UNICOS 21

int main() {
    int vetor[TAM];
    int vetor_unicos[TAM_UNICOS] = {0};

    const int VALOR_MAXIMO = 20; //valor máximo para número randômicos
    int i, j;
    int contador_unicos = 0;

    srand(time(0)); //gera uma nova cadeia de números aleatória

    for (i = 0; i < TAM; i++) {
        /* função rand() retorna um número aleatório entre 0 e o valor
        definido na variável de sistema RAND_MAX. O calculo abaixo converte para
        um numero entre 0 e VALOR_MAXIM */
        vetor[i]= (int) (rand() / (double) RAND_MAX * (VALOR_MAXIMO + 1));
        printf("%d ", vetor[i]);

        for (j = 0; j < TAM_UNICOS; j++) {
            if (j == vetor[i]) {
                vetor_unicos[j] += 1;
            }
        }
    }

    for (j = 0; j < TAM_UNICOS; j++) {
        if (vetor_unicos[j] == 1) {
            contador_unicos++;
        }
    }

    printf("\n\nTotal de elementos distintos: %d", contador_unicos);

    return 0;
}
