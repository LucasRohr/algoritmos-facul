#include <stdio.h>
#include <string.h>

#define TAM_MAX 40

int main()
{
    char string1[TAM_MAX];
    char string2[TAM_MAX];
    char string_resultado[TAM_MAX + TAM_MAX + 1];

    printf("\nDigite a string 1:\n");
    fgets(string1, TAM_MAX, stdin);
    string1[strcspn(string1, "\n")] = '\0'; // Remove first occurrence of line break

    printf("\n\nDigite a string 2:\n");
    fgets(string2, TAM_MAX, stdin);
    string1[strcspn(string2, "\n")] = '\0'; // Remove first occurrence of line break

    strcat(string_resultado, string1);
    strcat(string_resultado, string2);
    fputs(string_resultado, stdout);
}