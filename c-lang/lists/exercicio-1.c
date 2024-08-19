#include <time.h> // Biblioteca necess�ria para random
#include <stdlib.h>
#include<stdio.h>
#define TAM 10
#define TAM_UNICOS 21

int main() {
    int vetor[TAM];
    int vetor_unicos[TAM_UNICOS] = {0};

    const int VALOR_MAXIMO = 20; //valor m�ximo para n�mero rand�micos
    int i, j;
    int contador_unicos = 0;

    srand(time(0)); //gera uma nova cadeia de n�meros aleat�ria

    for (i = 0; i < TAM; i++) {
        /* fun��o rand() retorna um n�mero aleat�rio entre 0 e o valor
        definido na vari�vel de sistema RAND_MAX. O calculo abaixo converte para
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
