#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, l;
    int d = -4;
    float k;

    l = 0;
    j = 3;

    // Forma 1

    printf("Forma 1:\n\n");

    for(i = 2; i < 4; i++) {
        while(j >= 0) {
            k = i + j;
            j--;
            d++;

            if (d > 0) j -= d;

            printf("J=%3i, K=%6.2f, L=%3i\n", j, k, l);
        }

        j = 0;
        l += i;
    }

    printf("\n I=%3i", i);

    // ===============================
    // Prints da execucao:

    // 1) d = -4
    // J=bbb2,K=bbbbbb5.00,L=bbb0

    // 2) d = -3
    // J=bbb1,K=bbbbbb4.00,L=bbb0

    // 3) d = -2
    // J=bbb0,K=bbbbbb3.00,L=bbb0

    // 4) d = -1
    // J=bbb-1,K=bbbbbb2.00,L=bbb0

    // 5) d = 0
    // J=bbb-2,K=bbbbbb3.00,L=bbb2

    // 6) d = 0
    // I=bbb3

    // ===============================

    // Forma 2

    printf("\n\nForma 2:\n\n");

    d = -4;
    l = 0;
    k = 0.0;
    j = 3;

    i = 2;

    while(i < 4) {
        do {
            k = i + j;
            j--;
            d++;

            if (d > 0) j -= d;

            printf("J=%3i, K=%6.2f, L=%3i\n", j, k, l);
        } while(j >= 0);

        j = 0;
        l += i;

        i++;
    }

    printf("\n I=%3i", i);

    return 0;
}