// Program that takes 3 values to return if they are sides of triangle, classifying it if the values are valid

#include <stdio.h>
#include <math.h>

int main() {
    int value_1, value_2, value_3;

    printf("Digite o primeiro valor (X):\n");
    scanf("%d",&value_1);

    printf("Digite o segundo valor (Y):\n");
    scanf("%d",&value_2);

    printf("Digite o terceiro valor (Z):\n");
    scanf("%d",&value_3);

    // First test to see if it is not a triangle

    if (((value_1 + value_2) <= value_3 && value_1 < abs(value_2 + value_3)) || ((value_2 + value_3) <= value_1 && value_2 < abs(value_1 + value_3)) || ((value_1 + value_3) <= value_2 && value_3 < abs(value_1 + value_2))) {
        printf("Isso nao eh um triangulo!");
    } else if (value_1 == value_2 && value_1 == value_3) {
        printf("Isso é um triangulo equilatero!");
    } else if(value_1 != value_2 && value_1 != value_3 && value_2 != value_3) {
        printf("Isso é um triangulo escaleno!");
    } else {
        printf("Isso é um triangulo isosceles!");
    }

    return 0;
}
