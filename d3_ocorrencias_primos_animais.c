/*
 * Desafio 3 - Le 15 inteiros, conta ocorrencias e classifica cada numero
 * (Primo - impar, Primo - par, Par, Nao repetido). A soma das ocorrencias dos
 * primos com quantidade impar define quantos animais cadastrar. Os numeros
 * nao repetidos usam a sua posicao para buscar o animal correspondente.
 */
#include <stdio.h>

#define N 15

int ehPrimo(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int contar(int v[], int n, int x) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            c++;
        }
    }
    return c;
}

int primeiraOcorrencia(int v[], int i) {
    for (int j = 0; j < i; j++) {
        if (v[j] == v[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int vet[N];
    char animais[N][50];
    int soma = 0;

    for (int i = 0; i < N; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    printf("\nNumero  Ocorrencias  Classificacao\n");
    for (int i = 0; i < N; i++) {
        if (!primeiraOcorrencia(vet, i)) {
            continue;
        }

        int c = contar(vet, N, vet[i]);
        printf("%-8d%-13d", vet[i], c);

        if (c == 1) {
            printf("Nao repetido\n");
        } else if (ehPrimo(vet[i]) && c % 2 != 0) {
            printf("Primo - impar\n");
            soma += c;
        } else if (ehPrimo(vet[i])) {
            printf("Primo - par\n");
        } else if (c % 2 == 0) {
            printf("Par\n");
        } else {
            printf("Nao primo - impar\n");
        }
    }

    printf("\nCadastre %d animais:\n", soma);
    for (int i = 0; i < soma; i++) {
        printf("Animal %d: ", i + 1);
        scanf(" %49[^\n]", animais[i]);
    }

    printf("\nSaida:\n");
    for (int i = 0; i < N; i++) {
        if (contar(vet, N, vet[i]) == 1) {
            if (i + 1 <= soma) {
                printf("Posicao %d (numero %d): %s\n", i + 1, vet[i], animais[i]);
            } else {
                printf("Posicao %d (numero %d): Nao existe correspondencia.\n", i + 1, vet[i]);
            }
        }
    }

    return 0;
}
