#include <stdio.h>

#define JANEIRO "Janeiro"
#define FEVEREIRO "Fevereiro"
#define MARCO "Marco"
#define ABRIL "Abril"
#define MAIO "Maio"
#define JUNHO "Junho"
#define JULHO "Julho"
#define AGOSTO "Agosto"
#define SETEMBRO "Setembro"
#define OUTUBRO "Outubro"
#define NOVEMBRO "Novembro"
#define DEZEMBRO "Dezembro"

#define TAMANHO_MESES 12
#define TAMANHO_STRING_MES 9
#define TAMANHO_DIAS 30

#define INDICE_SETEMBRO 8
#define INDICE_DEZEMBRO 11

#define PRIMEIRO_DIA_PRIMAVERA 21
#define ULTIMO_DIA_PRIMAVERA 20

int main() {
    int medias_pluviometricas [TAMANHO_DIAS][TAMANHO_MESES];
    char meses [TAMANHO_MESES][TAMANHO_STRING_MES] = {
        JANEIRO,
        FEVEREIRO,
        MARCO,
        ABRIL,
        MAIO,
        JUNHO,
        JULHO,
        AGOSTO,
        SETEMBRO,
        OUTUBRO,
        NOVEMBRO,
        DEZEMBRO
    };

    int i, j; // Iteradores da lista
    int dia_atual_media = 1;
    int valor_base_media = 1;

    for (i = 0; i < TAMANHO_DIAS; i++) {
        for (j = 0; j < TAMANHO_MESES; j++) {
            // Modo arbitrario para calcular uma media diaria com base no dia e mes
            medias_pluviometricas[i][j] = 1000 - (i + j) - valor_base_media;
            valor_base_media += 50;
        }

        valor_base_media = 1;
    }

    printf("%s%16s%13s\n", "Mes", "Dia", "Media");

    // Itera os meses de setembro até dezembro
    for (j = INDICE_SETEMBRO; j < TAMANHO_MESES; j++) {
        // Se for setembro, deve iterar apenas do dia 22 até o final do mes
        if (j == INDICE_SETEMBRO) {
            for (i = PRIMEIRO_DIA_PRIMAVERA; i < TAMANHO_DIAS; i++) {
                printf("%s%10d\t%8d\n", meses[j], dia_atual_media, medias_pluviometricas[i][j]);
                dia_atual_media++;
            }
        } else
            // Se for dezembro, deve iterar do primeiro dia do mes até o dia 21 (fim da primavera)
            if (j == INDICE_DEZEMBRO) {
                for (i = 0; i < ULTIMO_DIA_PRIMAVERA; i++) {
                    printf("%s%10d\t%8d\n", meses[j], dia_atual_media, medias_pluviometricas[i][j]);
                    dia_atual_media++;
                }
            // Caso o mes não for setembro e nem dezembro, iterar normalmente por todos os dias do mês
            } else {
                for (i = 0; i < TAMANHO_DIAS; i++) {
                    printf("%s%10d\t%8d\n", meses[j], dia_atual_media, medias_pluviometricas[i][j]);
                    dia_atual_media++;
                }
            }
    }

    return 0;
}
