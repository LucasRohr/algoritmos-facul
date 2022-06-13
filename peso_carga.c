/*
Este programa pega pesos de produtos com suas embalagens e os usa para o cálculo de peso final da carga
*/

#include <stdio.h>
int main(void) {
    const int PESO_UNIDADE_CELULAR = 100;  /*Declaração da constante de peso de um celular*/
    const int PESO_UNIDADE_WEBCAM = 45; /*Declaração da constante de peso de uma webcam*/

    int total_celular; /*Declaração do valor total de itens para celular*/
    int total_webcam; /*Declaração do valor total de itens para webcam*/

    int peso_embalagem_celular; /*Declaração do valor de peso de embalagem para celular*/
    int peso_embalagem_webcam;  /*Declaração do valor de peso de embalagem para webcam*/

    int peso_total_celular; /*Declaração do valor de peso total para celular*/
    int peso_total_webcam; /*Declaração do valor de peso total para webcam*/
    int peso_carga; /*Declaração do valor de peso total da carga*/

    printf("Digite a quantidade de celulares:\n");
    scanf("%d", &total_celular);

    printf("Digite a quantidade de webcams:\n");
    scanf("%d", &total_webcam);

    printf("Digite o peso de uma embalagem de celular:\n");
    scanf("%d", &peso_embalagem_celular);

    printf("Digite o peso de uma embalagem de webcam:\n");
    scanf("%d", &peso_embalagem_webcam);

    peso_total_celular = (total_celular * PESO_UNIDADE_CELULAR) + (total_celular * peso_embalagem_celular);
    peso_total_webcam = (total_webcam * PESO_UNIDADE_WEBCAM) + (total_webcam * peso_embalagem_webcam);

    peso_carga = peso_total_celular + peso_total_webcam;

    printf("Peso total da carga em gramas: %d\n", peso_carga);

    getchar();
    printf("Terminou");

    return(0);
}

