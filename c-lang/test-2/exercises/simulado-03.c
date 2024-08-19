#include <stdio.h>

#define TAM_NOTAS 3
#define VALOR_SOMA_NOTA 0.5

float calcula_nova_media_notas(float notas[]) {
    float soma_media = 0.0;
    float novas_notas[TAM_NOTAS];

    int i;

    for(i = 0; i < TAM_NOTAS; i++) {
        novas_notas[i] = notas[i] + VALOR_SOMA_NOTA;
        soma_media += novas_notas[i];
    }

    return soma_media / TAM_NOTAS;
}

int main() {


    return 0;
}