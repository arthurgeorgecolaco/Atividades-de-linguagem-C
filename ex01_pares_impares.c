/*
 * Laços - Exercicio 1: le 10 inteiros, informa se cada um e par ou impar e,
 * no final, mostra a quantidade de pares e de impares.
 */
#include <stdio.h>

int main() {
    int num, pares = 0, impares = 0;

    for (int i = 1; i <= 10; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &num);

        if (num % 2 == 0) {
            printf("Par\n");
            pares++;
        } else {
            printf("Impar\n");
            impares++;
        }
    }

    printf("Pares: %d\nImpares: %d\n", pares, impares);
    return 0;
}
