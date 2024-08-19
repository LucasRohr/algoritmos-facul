#include <stdio.h>
#include <string.h>

#define TAMANHO_TEXTO 100
#define ESPACO ' '

int main() {
    char texto [TAMANHO_TEXTO];
    char texto_auxiliar [TAMANHO_TEXTO];

    int total_caracteres = 0;
    int total_palavras = 0;

    int i;

    printf("Digite um texto:\n");
    gets(texto);

    for(i = 0; i < strlen(texto); i++) {
        if (texto[i] != ESPACO) {
            total_caracteres++;
        }
    }

    printf("\n\nTotal de caracteres do texto informado: %d\n", total_caracteres);

    for(i = 0; i < strlen(texto) - 1; i++) {
        // Para nao contar cada espaco como uma palavra pela existencia de varios espacos
        // seguidos, apenas conta palavra se o char atual for espaco e o proximo nao for
        if(texto[i] == ESPACO && texto[i + 1] != ESPACO) {
            total_palavras++;
        }
    }

    printf("\n\nTotal de palavras do texto informado: %d\n", total_palavras);

    strcpy(texto_auxiliar, texto);

    for(i = 0; i < strlen(texto_auxiliar); i++) {
        texto_auxiliar[i] = toupper(texto_auxiliar[i]);
    }

    printf("Texto auxiliar modificado:\n");
    puts(texto_auxiliar);

    return 0;
}
