#include <stdio.h>
#include <string.h>

#define TAM_ATLETAS 3

typedef struct atleta {
    char nome[30];
    int idade;
    float altura;
} ATLETA;

int abre_arquivo(FILE *arq) {
    arq = fopen("atletas", "r+w");

    if (!arq) {
        printf("erro ao abrir arquivo");
        return 0;
    } else {
        return 1;
    }
}

void grava_atleta(FILE *arq, ATLETA *atleta) {
    int abriu_arquivo;

    abriu_arquivo = abre_arquivo(arq);

    if(abriu_arquivo) {
        fwrite(atleta, sizeof(ATLETA), 1, arq);
    }

    fclose(arq);
}

void grava_lista_atletas(FILE *arq, ATLETA atletas[]) {
    int i;

    i = 0;

    while(i < TAM_ATLETAS) {
        grava_atleta(arq, &(atletas[i]));
        i++;
    }

    fclose(arq);
}

void le_lista_atletas(FILE *arq, ATLETA atletas[]) {
    int abriu_arquivo, i;

    abriu_arquivo = abre_arquivo(arq);

    i = 0;

    if (abriu_arquivo) {
        while(!feof(arq) && i < TAM_ATLETAS) {
            if(fread(&(atletas[i]), sizeof(ATLETA), 1, arq) == 1) {
                i++;
            } else {
                printf("erro ao ler atleta no arquivo");
                fclose(arq);
            }
        }
    }

    fclose(arq);
}

void atualiza_altura_atleta(FILE *arq) {
    char nome_atleta[50];
    int i, abriu_arquivo;
    float nova_altura;

    ATLETA atleta_procurado;

    printf("digite o nome do atleta a ter a altura atualizada:");
    gets(nome_atleta);

    printf("digite a nova altura:");
    scanf("%f", &nova_altura);

    i = 0;
    abriu_arquivo = abre_arquivo(arq);

    if (abriu_arquivo) {
        while(!feof(arq) && i < TAM_ATLETAS && strcmp(atleta_procurado.nome, nome_atleta) != 0) {
            if (fread(&atleta_procurado, sizeof(ATLETA), 1, arq) == 1) {
                i++;
            }
        }

        atleta_procurado.altura = nova_altura;

        fwrite(&atleta_procurado, sizeof(ATLETA), 1, arq);
    }

    fclose(arq);
}

int main() {
    FILE *arq;
    ATLETA atletas[3] = { { "jose", 20, 170.3 }, { "cristo", 20, 170.3 }, { "armando v", 20, 170.3 } };

    abre_arquivo(arq);
    grava_lista_atletas(arq, atletas);

    return 0;
}