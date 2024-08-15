#include <stdio.h>

float sumValues(int value) {
    int sum = 0;

    if (value < 0) {
        return -1;
    }

    for (int i = 0; i <= value; i++) {
        sum += i; 
    }

    return sum;
}

int main() {
    int result = sumValues(6);

    printf("Soma = %d", result);
}