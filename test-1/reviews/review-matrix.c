#include <stdio.h>

#define NUM_FILAS 20
#define NUM_POLTRONAS 4
#define NUM_PASSAGEIROS 3

#define OCUPADO 1
#define LIVRE 0

int main() {
    int lugares [NUM_FILAS][NUM_POLTRONAS] = {0};
    
    int i, j;
    int fila_escolha, poltrona_escolha;

    i = 0;

    while (i < NUM_PASSAGEIROS) {
        i++;

        printf("Digite qual a fila quer sentar:\n");
        scanf("%d", &fila_escolha);

        printf("\n\nDigite qual a poltrona quer sentar:\n");
        scanf("%d", &poltrona_escolha);

        if (lugares[fila_escolha - 1][poltrona_escolha - 1] == LIVRE) {
            lugares[fila_escolha - 1][poltrona_escolha - 1] = OCUPADO;

            printf("\n\nLugar Fila %d | Poltrona %d reservado com sucesso\n", fila_escolha, poltrona_escolha);
        } else {
            printf("\n\nLugar já escolhido, sinto muito!\n");
        }
    }

    // Percorrer matriz

    for (i = 0; i < NUM_FILAS; i++) {
        for (j = 0; j < NUM_POLTRONAS; j++) {
            printf("Lugar de fila %d e poltrona %d\n", i + 1, j + 1);
            
            if (lugares[i][j] == OCUPADO) {
                printf("\nLugar ocupado!\n");
            } else {
                printf("Lugar livre!\n\n");
            }
        }
    }

    return 0;
}