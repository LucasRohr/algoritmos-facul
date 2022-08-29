#include <stdio.h>
#include <string.h>

#define TAMNOME 100
#define TAM_LISTA_JOGADORES 6
#define NOME_ARQUIVO "pratica11"

typedef struct {
    char nome[TAMNOME];
    int pontuacao;
} JOGADOR;

typedef struct {
    char nome[TAMNOME];
    int cogumelos_colhidos;
} FAZENDEIRO;

void CopiaJogador(JOGADOR *jogador, FAZENDEIRO *fazendeiro) {
    strcpy(fazendeiro->nome, jogador->nome);
    jogador->pontuacao = fazendeiro->cogumelos_colhidos;
}

void trocaJogador(JOGADOR *jogador1, JOGADOR *jogador2) {
    JOGADOR temp = *jogador1;

    *jogador1 = *jogador2;
    *jogador2 = temp;
}

void OrdenaListaJogadores(JOGADOR jogadores[]) {
    int i, j, indice_menor;
    //int tamanho_lista = sizeof(jogadores)/sizeof(jogadores[0]);

    for (i = 0; i < TAM_LISTA_JOGADORES - 1; i++) {
        indice_menor = i;

        for (j = i + 1; j < TAM_LISTA_JOGADORES; j++) {
            if (jogadores[j].pontuacao < jogadores[indice_menor].pontuacao) {
                indice_menor = j;
            }

            if (indice_menor != i) {
                trocaJogador(&(jogadores[indice_menor]), &(jogadores[i]));
            }
        }
    }
}

void OrdenaJogadores(JOGADOR jogador) {
    JOGADOR jogadores[TAM_LISTA_JOGADORES] = {{"Jorge", 10}, {"Alice", 5}, {"Alvin", 30}, {"Cleiton", 8}, {"Fabia", 22}};

    jogadores[TAM_LISTA_JOGADORES - 1] = jogador;

    OrdenaListaJogadores(jogadores);
}

void ImprimeRanking(JOGADOR jogadores[]) {
    int i;

    OrdenaListaJogadores(jogadores);

    for(i = 0; i < TAM_LISTA_JOGADORES; i++) {
        if (strlen(jogadores[i].nome) > 0) {
            printf("Jogador: %s\n", jogadores[i].nome);
            printf("Pontuacao: %d\n\n", jogadores[i].pontuacao);
        }
    }
}

void EscreveJogadoresArquivo(JOGADOR jogadores[], FILE *arq) {
    int i;

    for(i = 0; i < TAM_LISTA_JOGADORES; i++) {
        fwrite(&(jogadores[i]), sizeof(JOGADOR), 1, arq);
    }

    fclose(arq);
}

void SalvaJogador(JOGADOR jogadores[], FILE *arq) {
    if(!(arq = fopen(NOME_ARQUIVO,"wb"))) {
        printf("Erro de criacao");
    } else {
        EscreveJogadoresArquivo(jogadores, arq);
    }
}

int main2() {
    JOGADOR jogador1 = { "Claudio", 15 };
    FAZENDEIRO fazendeiro = { "Ernesto", 60 };

    JOGADOR jogadores_ranking[TAM_LISTA_JOGADORES] = {{"Joj", 89}, {"Alice", 5}, {"Lurde", 25}, {"Cleiton rasta", 12}, {"Fabia", 22}, {"Lol", 20}};

    FILE arquivo;

    CopiaJogador(&jogador1, &fazendeiro);

    OrdenaJogadores(jogador1);

    ImprimeRanking(jogadores_ranking);

    SalvaJogador(jogadores_ranking, &arquivo);

    return 0;
}


