#include <stdio.h>
#include <string.h>

#define TAMANHO_TEXTO 100
#define ESPACO ' '

#define VOGAL_A 'A'
#define VOGAL_E 'E'
#define VOGAL_I 'I'
#define VOGAL_O 'O'
#define VOGAL_U 'U'

#define HASHTAG '#'

int main() {
    char texto [TAMANHO_TEXTO];

    int i;
    int indice_metade_string;
    char auxiliar_troca_char;

    printf("Digite um texto:\n\n");
    gets(texto);

    if (strlen(texto) % 2 == 0) {
        indice_metade_string = (strlen(texto) / 2) - 1;
    } else {
        indice_metade_string = (int) (strlen(texto) / 2);
    }

    // Para assegurar a troca de letra por letra, remove todos os espacos
    for(i = 0; i < strlen(texto); i++) {
        if (i == ESPACO) {
            texto[i] = '';
        }
    }

    // percorre cada char e se o indice for da segunda metade da string,
    // usa uma auxiliar para trocar o char atual pelo correspondente da segunda metade
    for(i = 0; i < strlen(texto); i++) {
        if (i >= indice_metade_string) {
            auxiliar_troca_char = texto[i];
            texto[i] = toupper(texto[strlen(texto) - (i + 1)]);
            texto[strlen(texto) - (i + 1)] = toupper(auxiliar_troca_char);
        }
    }

    printf("\n\nTexto modificado segundo as regras de A: %s\n\n", texto);

    for(i = 0; i < strlen(texto); i++) {
        switch(toupper(texto[i])) {
            case VOGAL_A:
            case VOGAL_E:
            case VOGAL_I:
            case VOGAL_O:
            case VOGAL_U:
                texto[i] = HASHTAG;

                break;
            default:
                break;
        }
    }

    printf("\n\nTexto modificado segundo as regras de B: %s\n\n", texto);

    return 0;
}
