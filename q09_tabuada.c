/* Funcoes - Questao 9: funcao mostrarTabuada */
#include <stdio.h>

void mostrarTabuada(int n) {
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    mostrarTabuada(num);

    return 0;
}
