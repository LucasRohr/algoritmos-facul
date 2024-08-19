#include <stdio.h>

float calculateAvg(int grade1, int grade2, int grade3) {
    return (grade1 + grade2 + grade3) / 3;
}

int main() {
    int grade1;
    int grade2;
    int grade3;

    int sum = 0;
    int product = 1;

    printf("Digite a nota 1:\n");
    scanf("%d", &grade1);

    printf("Digite a nota 2 2:\n");
    scanf("%d", &grade2);

    printf("Digite a nota 3:\n");
    scanf("%d", &grade3);

    if (grade1 < 0 || grade2 < 0 || grade3 < 0) {
        printf("Erro: Valor negativo");

        return 0;
    }

    float avg = calculateAvg(grade1, grade2, grade3);

    if (avg <= 4.0) {
        printf("Conceito D");
    } else if (avg > 4.0 && avg <= 7.0) {
        printf("Conceito C");
    } else if (avg > 7.0 && avg <= 9.0) {
        printf("Conceito B");
    } else {
        printf("Conceito A");
    }

    return 0;
}