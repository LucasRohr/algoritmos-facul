#include <stdio.h>
#include <string.h>

#define TAM_STRING 100
#define TAM_NOTAS 2
#define TAM_ALUNOS 5

typedef struct aluno {
    int id;
    char nome[TAM_STRING];
    float notas[TAM_NOTAS];
} ALUNO;

int abre_arquivo(FILE *arq) {
    arq = fopen("txt_test.txt", "r+");

    if(arq) {
        return 1;
    } else {
        printf("erro ao abrir arquivo txt");
        return 0;
    }
}

void grava_caractere(char caractere, FILE *arq) {
    int abriu_arquivo;

    abriu_arquivo = abre_arquivo(arq);

    if (abriu_arquivo) {
        putc(caractere, arq);
    }
}

void grava_string(char string[], FILE *arq) {
    int abriu_arquivo;

    abriu_arquivo = abre_arquivo(arq);

    if (abriu_arquivo) {
        fputs(string, arq);
    }

    fclose(arq);
}

void le_string(char string[], int tam_string, FILE *arq) {
    int abriu_arquivo;

    abriu_arquivo = abre_arquivo(arq);

    if (abriu_arquivo) {
        fgets(string, tam_string, arq);
    }

    fclose(arq);
}

// Exemplo 3 dos Slides de Aula

int conta_separadores_string(char string[], char separador, int tam_string) {
    int i, contador_separadores = 0;

    for(i = 0; i < tam_string; i++) {
        if (strcmp(string[i], separador) == 0) {
            contador_separadores++;
        }
    }

    return contador_separadores;
}

void le_alunos_arquivo(ALUNO alunos[], FILE *arq) {
    int abriu_arquivo, index_alunos, i, j, contador_separadores;
    char linha_arquivo[TAM_STRING];

    abriu_arquivo = abre_arquivo(arq);

    if (abriu_arquivo) {
        index_alunos = 0;

        while(!feof(arq) && index_alunos < TAM_ALUNOS) {
            linha_arquivo = fgets(linha_arquivo, TAM_STRING, arq);
            contador_separadores = conta_separadores_string(linha_arquivo, ",", TAM_STRING);

            for(i = 0; i < contador_separadores; i++) {
                alunos[index_alunos].id = atoi(strtok(linha_arquivo, ","));
                strcpy(alunos[index_alunos].nome, strtok(NULL, ","));

                for(j = 0; j < TAM_NOTAS; j++) {
                    alunos[index_alunos].notas[j] = atof(strtok(NULL, ","));
                }
            }

            index_alunos++;
        }
    }

    fclose(arq);
}

float calcula_media_alunos(ALUNO alunos[], int total_alunos) {
    float soma_media = 0.0;
    int i, j;

    for(i = 0; i < total_alunos; i++) {
        for(j = 0; j < TAM_NOTAS; j++) {
            soma_media += alunos[i].notas[j];
        }
    }

    return soma_media / total_alunos;
}


int main() {
    FILE *arquivo = NULL;
    char stringao[TAM_STRING] = "o senhor das ameixas sera breve em seu pronunciamento matinal";
    char stringao_lido[TAM_STRING];

    ALUNO alunos[TAM_ALUNOS];
    float media_alunos;

    grava_string(stringao, arquivo);
    grava_caractere('_', arquivo);

    le_string(stringao_lido, TAM_STRING, arquivo);

    printf("stringao lido foi %s", stringao_lido);

    // Exemplo 3

    le_alunos_arquivo(alunos, arquivo);

    media_alunos = calcula_media_alunos(alunos, TAM_ALUNOS);

    printf("media dos alunos = %.2f", media_alunos);

    return 0;
}
