#include <stdio.h>

#define SIZE 10

int main()
{
    int array[SIZE];
    int *pointer, *end_pointer;

    pointer = array;            // start
    end_pointer = array + SIZE; // finish

    while (pointer < end_pointer)
    {
        printf("Digite um valor:");
        scanf("%d", pointer);

        pointer++;
    }

    pointer = array;

    while (pointer < end_pointer)
    {
        *pointer = *pointer * 10;

        printf("%d\n", *pointer);

        pointer++;
    }

    return 1;
}