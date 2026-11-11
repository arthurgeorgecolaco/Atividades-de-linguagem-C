/* Funcoes - Questao 8: funcao ehPrimo (divisores ate i * i <= n) */
#include <stdio.h>

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

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if (ehPrimo(num)) {
        printf("%d e primo.\n", num);
    } else {
        printf("%d nao e primo.\n", num);
    }

    return 0;
}
