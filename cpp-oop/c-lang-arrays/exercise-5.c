#include <stdio.h>
#include <string.h>

#define TAM_MAX 50

int main()
{
    char string1[TAM_MAX];
    char string2[TAM_MAX];

    printf("\nDigite a string 1:\n");
    fgets(string1, TAM_MAX, stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("\n\nDigite a string 2:\n");
    fgets(string2, TAM_MAX, stdin);
    string1[strcspn(string2, "\n")] = '\0';

    if (strcmp(string1, string2) == 0)
    {
        printf("\nStrings iguais!\n");
    }
    else
    {
        strcat(string1, string2);
        printf("\n\n%s", string1);
    }
}