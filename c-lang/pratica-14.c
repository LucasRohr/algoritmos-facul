#include<stdio.h>
#include <string.h>

#define EXPRESSAO_TESTE_1 "( 38*(20+x)/80 )/128+(4/(38+85*(32-x)))"
#define EXPRESSAO_TESTE_2 "( 38*(20+x)/80 )/128+(4/(38+85*(32-x))"
#define EXPRESSAO_TESTE_3 ") 38*(20+x)/80 )/128+(4/(38+85*(32-x))("
#define EXPRESSAO_TESTE_4 "(38*(20+x)/80)/128*(4/x))-38+85*(32-x)*(33/y)"

int func_soma(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return n + func_soma(n - 2);
}

int func_conta(char *string, char caractere) {
    if (*string == '\0') {
        return 0;
    }

    if (*string && string[0] == caractere) {
        return 1 + func_conta(string + 1, caractere);
    }

    return func_conta(string + 1, caractere);
}

int verificaExpressao(char *expressao) {
    if (*expressao == '\0' || expressao[0] == ')') {
        return 0;
    }

    if (expressao[0] == '(') {
        if (verificaExpressao(expressao + 1) == 0) {
            return 1;
        } else {
            return verificaExpressao(expressao + 1);
        }
    }

    return verificaExpressao(expressao + 1);
}

int main() {
    int teste_soma_par, teste_soma_impar;
    int test_contador_de_char;

    char caractere_busca = 'a';
    char string_teste[50] = "frase teste a";

    teste_soma_par = func_soma(8);
    teste_soma_impar = func_soma(7);

    test_contador_de_char = func_conta(string_teste, caractere_busca);

    printf("Resultado da soma com n par = %d\n", teste_soma_par);
    printf("Resultado da soma com n impar = %d\n\n", teste_soma_impar);

    printf("Numero de ocorrencias do char %c na string %s = %d\n\n", caractere_busca, string_teste, test_contador_de_char);

    printf("Resultado do teste da expressao %s = %d\n", EXPRESSAO_TESTE_1, verificaExpressao(EXPRESSAO_TESTE_1));
    printf("Resultado do teste da expressao %s = %d\n", EXPRESSAO_TESTE_2, verificaExpressao(EXPRESSAO_TESTE_2));
    printf("Resultado do teste da expressao %s = %d\n", EXPRESSAO_TESTE_3, verificaExpressao(EXPRESSAO_TESTE_3));

    return 0;
}
