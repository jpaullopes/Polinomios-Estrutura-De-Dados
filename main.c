#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

int main() {
    // Criação de polinômios
    Poli P = termo(3, 4, termo(-2, 2, termo(5, 0, NULL)));
    Poli Q = termo(1, 3, termo(2, 2, termo(-1, 1, NULL)));

    // Exibição dos polinômios
    printf("Polinomio P: ");
    exibep(P);
    printf("\n");

    printf("Polinomio Q: ");
    exibep(Q);
    printf("\n");

    // Soma dos polinômios
    Poli R = sum_base(P, Q);
    printf("Polinomio R (P + Q): ");
    exibep(R);
    printf("\n");

    // Avaliação do polinômio R para x = 2
    float resultado = valor(R, 2);
    printf("Valor de R para x = 2: %.2f\n", resultado);

    // Derivada do polinômio R
    Poli S = derivada(R);
    printf("Polinomio S (derivada de R): ");
    exibep(S);
    printf("\n");

    // Liberação da memória
    destroip(&P);
    destroip(&Q);
    destroip(&R);
    destroip(&S);

    return 0;
}