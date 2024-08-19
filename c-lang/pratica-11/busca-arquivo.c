#include <stdio.h>
#include <string.h>

#define TAMNOME 100
#define NOME_ARQUIVO "pratica11"
#define TAM_LISTA_JOGADORES 6

typedef struct {
    char nome[TAMNOME];
    int pontuacao;
} JOGADOR;

void LeArquivoJogadores(FILE *arq) {
    JOGADOR jogadores[TAM_LISTA_JOGADORES];
    int i = 0;

    if((arq = fopen(NOME_ARQUIVO,"rb")) == NULL) {
        printf("Erro abertura");
    } else {
        printf("Buscou do arquivo\n\n");

        while(!feof(arq) && i < TAM_LISTA_JOGADORES) {
            fread(&(jogadores[i]), sizeof(JOGADOR), 1, arq);
            i++;
        }

        fclose(arq);
    }

    ImprimeRanking(jogadores);
}

int main() {
    FILE arquivo;

    LeArquivoJogadores(&arquivo);

    return 0;
}
