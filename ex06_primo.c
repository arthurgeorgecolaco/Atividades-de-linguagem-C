/*
 * Laços - Exercicio 6: verifica se um inteiro positivo e primo testando todos
 * os divisores possiveis. Versao final: permite testar varios numeros.
 */
#include <stdio.h>

int main() {
    int num, ehPrimo;
    char continuar;

    do {
        printf("Digite um numero: ");
        scanf("%d", &num);

        ehPrimo = 1;
        if (num < 2) {
            ehPrimo = 0;
        } else {
            for (int i = 2; i < num; i++) {
                if (num % i == 0) {
                    ehPrimo = 0;
                    break;
                }
            }
        }

        if (ehPrimo) {
            printf("%d e primo\n", num);
        } else {
            printf("%d nao e primo\n", num);
        }

        printf("Testar outro? (S/s): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    return 0;
}
