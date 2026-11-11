/*
 * Desafio 4 - Cinco apostadores. Resultado = soma dos n primeiros termos de
 * Fibonacci (1, 1, 2, 3, 5...).
 * 1o lugar: maior resultado primo.
 * 2o lugar: maior resultado par entre os nao premiados.
 * 3o lugar: maior resultado acima da media entre os nao premiados.
 * Ninguem recebe duas premiacoes.
 */
#include <stdio.h>

#define N 5

long long somaFibonacci(int n) {
    long long a = 1, b = 1, soma = 0;

    for (int i = 1; i <= n; i++) {
        soma += a;
        long long prox = a + b;
        a = b;
        b = prox;
    }
    return soma;
}

int ehPrimo(long long n) {
    if (n < 2) {
        return 0;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char nomes[N][50];
    int valores[N];
    long long resultados[N];
    int premiado[N] = {0};
    int vencedor[3] = {-1, -1, -1};
    double media, soma = 0;

    for (int i = 0; i < N; i++) {
        printf("Nome do apostador %d: ", i + 1);
        scanf(" %49[^\n]", nomes[i]);

        do {
            printf("Valor inteiro positivo de %s: ", nomes[i]);
            scanf("%d", &valores[i]);
        } while (valores[i] <= 0);

        resultados[i] = somaFibonacci(valores[i]);
        soma += resultados[i];
    }
    media = soma / N;

    /* 1o lugar: maior primo */
    for (int i = 0; i < N; i++) {
        if (ehPrimo(resultados[i]) &&
            (vencedor[0] == -1 || resultados[i] > resultados[vencedor[0]])) {
            vencedor[0] = i;
        }
    }
    if (vencedor[0] != -1) {
        premiado[vencedor[0]] = 1;
    }

    /* 2o lugar: maior par entre os nao premiados */
    for (int i = 0; i < N; i++) {
        if (!premiado[i] && resultados[i] % 2 == 0 &&
            (vencedor[1] == -1 || resultados[i] > resultados[vencedor[1]])) {
            vencedor[1] = i;
        }
    }
    if (vencedor[1] != -1) {
        premiado[vencedor[1]] = 1;
    }

    /* 3o lugar: maior acima da media entre os nao premiados */
    for (int i = 0; i < N; i++) {
        if (!premiado[i] && resultados[i] > media &&
            (vencedor[2] == -1 || resultados[i] > resultados[vencedor[2]])) {
            vencedor[2] = i;
        }
    }
    if (vencedor[2] != -1) {
        premiado[vencedor[2]] = 1;
    }

    printf("\n=== Vencedores ===\n");
    for (int k = 0; k < 3; k++) {
        if (vencedor[k] != -1) {
            printf("%do lugar: %s\n", k + 1, nomes[vencedor[k]]);
        } else {
            printf("%do lugar: sem vencedor\n", k + 1);
        }
    }

    return 0;
}
