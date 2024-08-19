#include <stdio.h>
#include <string.h>

#define TAM_JOGADORES 2

typedef struct endereco {
    char cidade[50];\
    char rua[50];
    int numero;
} ENDERECO;

typedef struct jogador {
    char nome[50];
    int idade;
    float score;
    ENDERECO endereco;
} JOGADOR;

void mostra_jogador(JOGADOR jogador) {
    printf("nome = %s\n", jogador.nome);
    printf("idade = %d\n", jogador.idade);
    printf("score = %.2f\n", jogador.score);
    printf("cidade = %s\n\n", jogador.endereco.cidade);
}

void atualiza_endereco(JOGADOR *jogador, char nova_cidade[]) {
    strcpy(jogador->endereco.cidade, nova_cidade);
}

void incrementa_score_jogadores(JOGADOR jogadores[]) {
    int i;

    for(i = 0; i < TAM_JOGADORES; i++) {
        jogadores[i].score += 5.0;
        atualiza_endereco((jogadores + i), "rio de janeiro");
    }
}

int main() {
    ENDERECO endereco_j1 = { "sapucaia do sul", "david machado", 28 };
    JOGADOR jogador1 = { "alfredo", 23, 5.5, endereco_j1 };
    JOGADOR jogador2 = { "jorge", 15, 8.5, endereco_j1 };

    JOGADOR jogadores[TAM_JOGADORES] = { jogador1, jogador2 };

    mostra_jogador(jogador1);

    atualiza_endereco(&jogador1, "porto alegre");

    incrementa_score_jogadores(jogadores);

    mostra_jogador(jogadores[0]);
    mostra_jogador(jogadores[1]);

    return 0;
}
