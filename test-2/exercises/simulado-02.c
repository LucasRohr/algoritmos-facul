#include <stdio.h>
#include <string.h>

#define TAM_NOME_ARQUIVO 50
#define NOME_ARQUIVO_GRAVACAO "arq.txt"

// atribui ponteiro do arquivo para o arquivo aberto, retornando flag para verificar
// se abriu corretamente
int abre_arquivo(FILE *arquivo, char nome_arq[], char modo_abertura[]) {
    arquivo = fopen(nome_arq, modo_abertura);

    if(arquivo) {
        return 1;
    } else {
         printf("Erro ao abrir o arquivo");

         return 0;
    }
}

void grava_caracteres_filtrados(FILE *arquivo_abertura) {
    FILE *arquivo_gravacao;

    // flags para verificar se abriu cada arquivo
    int abriu_arquivo, abriu_arquivo_gravacao;
    char nome_arquivo[TAM_NOME_ARQUIVO];
    char caractere_atual_lido;

    printf("Digite o nome do arquivo a ser aberto: ");
    gets(nome_arquivo);

    // armazena flag para verificar se abriu aqruivo base em leitura
    abriu_arquivo = abre_arquivo(arquivo, nome_arquivo, "r");

    if (abriu_arquivo) {
        while(!feof(arquivo)) {
            // armazena caractere atual lido no ponteiro de busca do arquivo base
            caractere_atual_lido = getc(arquivo);

            // Decide o que fazer com base no caractere atual do arquivo
            switch(caractere_atual_lido) {
                // se for vogal, não faz nada
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    break;
                // se não for vogal, abre arquivo de gravacao e grava caractere se abriu com sucesso
                default:
                    abriu_arquivo_gravacao = abre_arquivo(arquivo_gravacao, NOME_ARQUIVO_GRAVACAO, "w+");

                    if(abriu_arquivo_gravacao) {
                        putc(caractere_atual_lido, arquivo_gravacao);
                    }

                    break;
            }
        }
    }

    fclose(arquivo);
}

int main() {
    return 0;
}