// Program that takes a pyramid base side measure and height to calculate its volume

#include <stdio.h>

#define VOLUME_DIVIDER 3

int main() {
    float base_side_measure;
    float pyramid_height;

    float base_area;

    float total_volume;

    printf("Informe a medida de um lado da base da pirâmide:\n");
    scanf("%f", &base_side_measure);

    printf("Informe a medida da altura da pirâmide:\n");
    scanf("%f", &pyramid_height);

    base_area = base_side_measure * base_side_measure;
    total_volume = (base_area * pyramid_height) / VOLUME_DIVIDER;

    printf("O volume total da pirâmide é: %.2f", total_volume);

    return 0;
}
