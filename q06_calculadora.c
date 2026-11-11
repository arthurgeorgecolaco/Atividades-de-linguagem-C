/* Funcoes - Questao 6: calculadora com uma funcao por operacao */
#include <stdio.h>

float soma(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    return a / b;
}

int main() {
    float n1, n2;
    char op;

    printf("Digite dois numeros: ");
    scanf("%f %f", &n1, &n2);

    printf("Operacao (+, -, *, /): ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            printf("Resultado: %.2f\n", soma(n1, n2));
            break;
        case '-':
            printf("Resultado: %.2f\n", subtracao(n1, n2));
            break;
        case '*':
            printf("Resultado: %.2f\n", multiplicacao(n1, n2));
            break;
        case '/':
            if (n2 != 0) {
                printf("Resultado: %.2f\n", divisao(n1, n2));
            } else {
                printf("Erro: divisao por zero!\n");
            }
            break;
        default:
            printf("Operacao invalida!\n");
    }

    return 0;
}
