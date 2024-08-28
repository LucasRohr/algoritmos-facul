#include <stdio.h>

int main()
{
    int value = 10;
    int *pointer = NULL;

    pointer = &value;

    *pointer = 13;

    printf("Novo valor da variavel (print usando ponteiro) = %d\n", *pointer);
    printf("Novo valor da variavel (print usando variavel) = %d", value);

    return 1;
}