#include <stdio.h>
#include <string.h>

#define TAMANHO_STRING 60

#define VOGAL_A 'A'
#define VOGAL_E 'E'
#define VOGAL_I 'I'
#define VOGAL_O 'O'
#define VOGAL_U 'U'

#define ESPACO ' '
#define ASTERISCO '*'

int main() {
    char s [TAMANHO_STRING];

    int i; // Iterador do for

    printf("Digite um texto:\n");
    gets(s);

    for(i = 0; i < strlen(s); i++) {
        // Em caso do char atual na iteracao ser uma das vogais, troca por asterico
        // Caso for um espaco, troca por um espaco vazio
        switch(s[i]) {
            case VOGAL_A:
            case VOGAL_E:
            case VOGAL_I:
            case VOGAL_O:
            case VOGAL_U:
                s[i] = ASTERISCO;
                break;
            case ESPACO:
                s[i] = '';
                break;
            default
                break;
        }
    }

    printf("\nTexto com vogais trocadas por asterisco: %s\n", s);

    return 0;
}
