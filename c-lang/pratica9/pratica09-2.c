
// Exercicio 01

// *(v+3) - Valido, 8
// *(q-1) - Invalido, retorna algum lixo, pois os indices de v podem nao ser sequenciais
// *&v[1] - Valido, 4
// *p+*q - Valido, 16
// 3*-*p/(*q)+*&i - Válido, 3 * (10/6) + 7

// Exercicio 03

#include <stdio.h>
int main() {
 int soma_maluca;

 int a[5] = {3, 4, 2, 4, 1};
 int b[5] = {2, 2, 1, 1, 5};
 int c[5] = {-1};
 int *p1;
 int *p2;
 int *p3;
 int *p4;

 p1 = &(a[2]);
 p2 = &(b[3]);
 p3 = p2 + b[3];
 p4 = p2;

 soma_maluca = 2* *p1 + *p3 + *p4;

 if(soma_maluca == 10)
 printf("VOCE CONSEGUIU! ");
}
