/*
Este programa pega dois inteiros, os soma e exibe o resultado na tela
*/

#include <stdio.h>
int main(void) {
    float a, b; /*Declaração da variável com os parâmetros */
    float soma; /*Declaração da variável com o resultado*/

    printf("Valor de A:\n");
    scanf("%f", &a);

    printf("Valor de B:\n");
    scanf("%f", &b);

    soma = a + b;

    printf("Resultado da soma: %.2f\n", soma);
    getchar();
    printf("Terminou");

    /*
    O comando getchar() para o programa ate que seja digitado algum caracter
    */

    return(0);
}
