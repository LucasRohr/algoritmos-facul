#include <stdio.h>

#define PI 3.14159

void main() {
    int a;
    int b;
    int c;
    int d;
    int e;

    float triangleArea;
    float rectanglePerimeter;
    float circleArea;

    printf("Digite o valor de A:\n");
    scanf("%d", &a);

    printf("Digite o valor de B:\n");
    scanf("%d", &b);

    printf("Digite o valor de C:\n");
    scanf("%d", &c);

    printf("Digite o valor de D:\n");
    scanf("%d", &d);

    printf("Digite o valor de E:\n");
    scanf("%d", &e);

    triangleArea = ((float)b * (float)c) / 2;
    rectanglePerimeter = a + b + c + d;
    circleArea = PI * e * e;

    printf("\nArea do triangulo: %f\n", triangleArea);
    printf("\nPerimetro do retangulo: %f\n", rectanglePerimeter);
    printf("\nArea do circulo: %f\n", circleArea);
}