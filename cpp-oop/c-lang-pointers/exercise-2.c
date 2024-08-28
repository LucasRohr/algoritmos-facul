#include <stdio.h>

// Whats does the bellow code produce?

int main()
{
    int a = 3, b = 2, *p = NULL, *q = NULL;

    p = &a;      // p = a address
    q = p;       // q = a address (stored in p)
    *q = *q + 1; // a = 4
    q = &b;      // q = b address
    b = b + 1;   // b = 3

    printf("% d\n", *q); // 3
    printf("% d\n", *p); // 4

    return 1;
}