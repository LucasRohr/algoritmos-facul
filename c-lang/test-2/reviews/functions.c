#include <stdio.h>

void printar_texto() {
    printf("%s", "texto daora\n");
}

void printar_soma(int valor1, int valor2) {
    printf("total da soma = %d\n", valor1 + valor2);
}

int verifica_maior_idade(int idade) {
    if (idade < 18) {
        return 0;
    } else {
        return 1;
    }
}

float altera_subtracao(float *valor1, float *valor2) {
    float auxiliar;

    auxiliar = *valor1;
    *valor1 = *valor2;
    *valor2 = auxiliar;

    return *valor1 - *valor2;
}

void altera_valor_lista(int *valor) {
    *valor += 1;
}

int soma_todos(int valores[], int total_valores) {
    int i, soma = 0;

    for(i = 0; i < total_valores; i++) {
        altera_valor_lista(&(valores[i]));
        soma += valores[i];
    }

    return soma;
}

void conta_string(char *str) {
    char *p = str; //p aponta para o primeiro caractere de str
    int tam = 0;

    while (*p != '\0') {
        tam++;
        p++;

    }

    printf("\nA string tem %d letras\n\n", tam);
}

int main() {
    int de_maior;
    float resultado_sub, valor1_sub = 2.0, valor2_sub = 5.5;
    int soma_todos_resultado;

    int valores_soma[5] = { 1, 2, 3, 4, 7 };

    printar_texto();
    printar_soma(4, 3);

    de_maior = verifica_maior_idade(17);
    printf("de maior = %d", de_maior);

    resultado_sub = altera_subtracao(&valor1_sub, &valor2_sub);
    printf("\nresultado_sub = %.2f", resultado_sub);

    soma_todos_resultado = soma_todos(valores_soma, 5);
    printf("\nsoma_todos_resultado = %d", soma_todos_resultado);

    conta_string("seu jorge");

    return 0;
}
