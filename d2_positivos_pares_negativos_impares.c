/*
 * Desafio 2 - Le 10 inteiros e separa os positivos e pares dos negativos e
 * impares, exibindo cada conjunto em ordem crescente.
 */
#include <stdio.h>

#define N 10

void ordenar(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void exibir(int v[], int n) {
    if (n == 0) {
        printf("Nenhum valor.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int num;
    int posPares[N], negImpares[N];
    int qtdPP = 0, qtdNI = 0;

    for (int i = 0; i < N; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &num);

        if (num > 0 && num % 2 == 0) {
            posPares[qtdPP] = num;
            qtdPP++;
        } else if (num < 0 && num % 2 != 0) {
            negImpares[qtdNI] = num;
            qtdNI++;
        }
    }

    ordenar(posPares, qtdPP);
    ordenar(negImpares, qtdNI);

    printf("\nPositivos e pares (crescente): ");
    exibir(posPares, qtdPP);
    printf("Negativos e impares (crescente): ");
    exibir(negImpares, qtdNI);

    return 0;
}
