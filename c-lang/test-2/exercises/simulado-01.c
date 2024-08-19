#include <stdio.h>
#include <string.h>

#define TAM_ARQUIVO 50
#define TAM_NOME_ARQUIVO 100

typedef struct {
    int codigo;
    char nome[5];
} ELEM;

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

void carrega(char nome_arq[], ELEM *elementos) {
    int i, abriu_arquivo;
    FILE *arquivo;

    // armazena flag para verificar se abriu aqruivo em leitura
    abriu_arquivo = abre_arquivo(arquivo, nome_arq, "r");

    if (abriu_arquivo) {
        i = 0;

        // enquanto não chegar ao fim do arquivo ou acabar a lista, grava um elemento
        // no indice i atual na lista
        while(!feof(arquivo) && i < TAM_ARQUIVO) {
            fread(&(elementos[i]), sizeof(ELEM), 1, arquivo);
            i++;
        }
    }

    fclose(arquivo);
}

int copia_duplicata(ELEM V1[], ELEM V2[]) {
    int i, j, copiou_item = 1;
    ELEM V3[TAM_ARQUIVO] = {};

    for(i = 0; i < TAM_ARQUIVO; i++) {
        // reseta indice de busca no segundo vetor
        j = 0;

        // enquanto nao achou o valor de V1 em V2 e não chegou no final do arquivo,
        // incrementa o indice de busca
        while(V2[j].codigo != V1[i].codigo && j < TAM_ARQUIVO) {
            j++;
        }

        // se o indice de busca for menor que o tamanho do arquivo, achou
        if (j < TAM_ARQUIVO) {
            // grava nova estrutura ELEM no V3
            V3[i] = { V2[j].codigo, V2[j].nome };
        }
    }

    return copiou_item;
}

void salva_duplicata(ELEM elementos[]) {
    int i, abriu_arquivo;
    char nome_arquivo[TAM_NOME_ARQUIVO];
    FILE *arquivo;

    printf("Digite o nome do arquivo para salvar a lista:");
    gets(nome_arquivo);

    // armazena flag para verificar se abriu aqruivo em escrita
    abriu_arquivo = abre_arquivo(arquivo, nome_arq, "w");

    if (arquivo) {
        for(i = 0; i < TAM_ARQUIVO; i++) {
            // Verifica se existe o elemento de indice atual com código na lista antes de tentar gravar
            if (elementos[i] && elementos[i].codigo) {
                fwrite(&(elementos[i]), sizeof(ELEM), 1, arquivo);
            }
        }
    }

    fclose(arquivo);
}

int main() {
    ELEM Vetor1[TAM_ARQUIVO];
    ELEM Vetor2[TAM_ARQUIVO];

    carrega("a1.dad", Vetor1);
    carrega("a2.dad", Vetor2);

    if(copia_duplicata(Vetor1, Vetor2) == 1) {
        printf("Não há duplicatas");
    }
}
