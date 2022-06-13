/*
Este programa pega dados de trabalho e família para cálculo do salário bruto, exibindo o resultado na tela
*/

#include <stdio.h>
int main(void) {
    const float SALARIO_FAMILIA_FILHO = 56.2;

    int horas_trabalhadas_mes; /*Declaração da variável das horas trabalhadas em um mês*/
    float valor_recebido_hora; /*Declaração da variável para receber o valor de ponto flutuante para valor de trabalho por hora */
    int numero_filhos; /*Declaração da variável para obter o número de filhos abaixo de 14 anos*/

    float salario_familia; /*Declaração da variável para calcular o salário família com base no número de filhos informado*/
    float salario_bruto;

    printf("Digite quantas horas foram trabalhadas no mes:\n");
    scanf("%d", &horas_trabalhadas_mes);

    printf("Digite quanto eh recebido por hora:\n");
    scanf("%f", &valor_recebido_hora);

    printf("Digite a quantidade de filhos abaixo de 14 anos:\n");
    scanf("%d", &numero_filhos);

    salario_familia = numero_filhos * SALARIO_FAMILIA_FILHO;
    salario_bruto = salario_familia + (valor_recebido_hora * horas_trabalhadas_mes);

    printf("Valor total do salario bruto: %.2f\n", salario_bruto);

    getchar();
    printf("Terminou");

    return(0);
}
