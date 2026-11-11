/* Funcoes - Questao 2: funcao calcularDobro */
#include <stdio.h>

int calcularDobro(int n) {
    return n * 2;
}

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("O dobro de %d e %d\n", num, calcularDobro(num));
    return 0;
}
