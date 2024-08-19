#include <stdio.h>

int main() {
    int vet[4] = {2, 4, 6, 8};

    printf("terceiro elemento do vetor = %d", *(vet + 2));
    printf("endereco do ultimo elemento do vetor = %d", (vet + 3));

    // c) imprime 2 + 1 = 3
    printf (“%d” , ++(*vet))

    // d)
    // Posicao vet[1] = 4088
    // Posicao vet[2] = 4090
    // Posicao vet + 3 = 4092

    return 0;
}
