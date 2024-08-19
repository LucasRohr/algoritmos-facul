#include <stdio.h>
#include <string.h>

int func_soma(int n) {
    if (n == 0 || n == 1) {
        return 0;
    }

    return n + func_soma(n - 2);
}

int func_conta(char *string, char caractere) {
    if (*string == '/0') {
        return 0;
    }

    if (*string == caractere) {
        return 1 + func_conta(string + 1, caractere);
    }

    return func_conta(string + 1, caractere);
}

int main() {
    int soma, contagem_caractere;
    char string_teste[100] = "string muito grande com algumas letras";
    char caractere_contagem = 'e';

    soma = func_soma(5);
    printf("soma = %d", soma);

    contagem_caractere = func_conta(string_teste, caractere_contagem);
    printf("total contagem de %c na string %s = %d", caractere_contagem, string_teste, soma);

    return 0;
}
