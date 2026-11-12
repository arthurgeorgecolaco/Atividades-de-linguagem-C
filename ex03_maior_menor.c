/*
 * Laços - Exercicio 3: le 10 inteiros e mostra o maior, o menor e a diferenca
 * entre eles. Restricao: nao usar vetores nem matrizes.
 */
#include <stdio.h>

int main() {
    int num, maior, menor;

    printf("Numero 1: ");
    scanf("%d", &num);
    maior = num;
    menor = num;

    for (int i = 2; i <= 10; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &num);

        if (num > maior) {
            maior = num;
        }
        if (num < menor) {
            menor = num;
        }
    }

    printf("Maior: %d\nMenor: %d\n", maior, menor);
    printf("Diferenca: %d\n", maior - menor);
    return 0;
}
