/* Funcoes - Questao 5: funcao ehPar */
#include <stdio.h>

int ehPar(int n) {
    if (n % 2 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if (ehPar(num)) {
        printf("%d e par.\n", num);
    } else {
        printf("%d e impar.\n", num);
    }

    return 0;
}
