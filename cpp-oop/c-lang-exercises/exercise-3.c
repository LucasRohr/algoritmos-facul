#include <stdio.h>

#define WORK_PERCENT 0.1
#define AVAL_PERCENT 0.6
#define TEST_PERCENT 0.3

void main() {
    float workGrade;
    float avalGrade;
    float testGrade;

    float workValue;
    float avalValue;
    float testValue;

    float finalGrade;

    printf("Digite a nota do trabalho:\n");
    scanf("%f", &workGrade);

    printf("\nDigite a nota da prova:\n");
    scanf("%f", &avalGrade);

    printf("\nDigite a nota do teste:\n");
    scanf("%f", &testGrade);

    workValue = workGrade * WORK_PERCENT;
    avalValue = avalGrade * AVAL_PERCENT;
    testValue = testValue * TEST_PERCENT;

    finalGrade = workValue + avalValue + testValue;

    printf("\nNota final: %.2f\n", finalGrade);
}