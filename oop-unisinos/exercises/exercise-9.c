#include <stdio.h>

#define MAX_VALUE 3000

void main() {
    for (int i = 0; i <= MAX_VALUE; i++) {
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }
}