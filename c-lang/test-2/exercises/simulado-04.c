#include <stdio.h>

#define VALOR_BUSCA 14

int busca_valor_lista(int valores[], int indice_atual) {
    // calcula tamanho do vetor
    int tamanho_vetor = sizeof(valores) / sizeof(int);

    // se chegou a fim do vetor, não achou o valor e retorna NULL
    if (indice_atual == tamanho_vetor - 1) {
        return NULL;
    }

    // se o valor não for o procurado, chama a propria funcao recursivamente
    // aumentando o indice de busca em 1
    if (valores[indice_atual] != VALOR_BUSCA) {
        return busca_valor_lista(valores, indice_atual + 1);
    // senao, achou o valor e retorna seu indice
    } else {
        return indice_atual;
    }
}

int main() {

    return 0;
}