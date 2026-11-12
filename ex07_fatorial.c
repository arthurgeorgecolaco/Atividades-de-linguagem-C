/*
 * Laços - Exercicio 7: le um inteiro entre 0 e 10 (repete se estiver fora do
 * intervalo) e calcula o fatorial.
 */
#include <stdio.h>

int main() {
    int num;
    long long fat = 1;

    do {
        printf("Numero entre 0 e 10: ");
        scanf("%d", &num);
        if (num < 0 || num > 10) {
            printf("Valor invalido!\n");
        }
    } while (num < 0 || num > 10);

    for (int i = 2; i <= num; i++) {
        fat *= i;
    }

    printf("%d! = %lld\n", num, fat);
    return 0;
}
