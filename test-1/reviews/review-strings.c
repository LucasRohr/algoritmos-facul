#include <stdio.h>
#include <string.h>

#define NUM_LISTAS 3
#define NUM_STRINGS 50
#define NUM_NOME_COMPLETO 100
#define TAMANHO_STRING_BUSCA 10

int main() {
    // Ler duas listas de strings de nome e sobrenome

    char lista_nomes [NUM_LISTAS][NUM_STRINGS];
    char lista_sobrenomes [NUM_LISTAS][NUM_STRINGS];

    int i, j;

    int indice_busca_nome;
    char maior_nome [NUM_STRINGS];
    char maior_sobrenome [NUM_STRINGS];
    char nome_completo [NUM_STRINGS];


    for (i = 0; i < NUM_LISTAS; i++) {
        printf("Digite o nome %d:\n", i + 1);
        gets(lista_nomes[i]);

        printf("Digite o sobrenome %d:\n", i + 1);
        gets(lista_sobrenomes[i]);
    }

    // Encontrar nome e sobrenome com tamanho maior que 10

    indice_busca_nome = 0;

    while (indice_busca_nome < NUM_LISTAS && strlen(lista_nomes[indice_busca_nome]) > TAMANHO_STRING_BUSCA) {
        indice_busca_nome++;
    }

    stpcpy(maior_nome, lista_nomes[indice_busca_nome]);

    indice_busca_nome = 0;

    while (indice_busca_nome < NUM_LISTAS && strlen(lista_sobrenomes[indice_busca_nome]) > TAMANHO_STRING_BUSCA) {
        indice_busca_nome++;
    }

    stpcpy(maior_sobrenome, lista_sobrenomes[indice_busca_nome]);

    printf("Maior nome %s:\n", maior_nome);
    printf("Maior sobrenome %s:\n", maior_sobrenome);

    // Concatenar nome e sobrenome encotrados e botar em variavel

    strcpy(nome_completo, strcat(maior_nome, " "));
    strcpy(nome_completo, strcat(nome_completo, maior_sobrenome));

    printf("Nome completo %s:\n", nome_completo);

    return 0;
}