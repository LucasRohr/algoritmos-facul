#include <stdio.h>

void main() {
    int val1;
    int val2;
    int greaterValue;
    int lessValue;

    printf("Digite o valor 1:\n");
    scanf("%d", &val1);

    printf("Digite o valor 2:\n");
    scanf("%d", &val2);

    if (val1 > val2) {
        greaterValue = val1;
        lessValue = val2;
    } else {
        greaterValue = val2;
        lessValue = val1;
    }

    for (int i = lessValue; i <= greaterValue; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }
}