/*
 * Laços - Exercicio 5: tabuada de 1 a 10 de um numero inteiro; depois pergunta
 * se o usuario quer outra (repete enquanto a resposta for S ou s).
 */
#include <stdio.h>

int main() {
    int num;
    char continuar;

    do {
        printf("Digite um numero: ");
        scanf("%d", &num);

        for (int i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", num, i, num * i);
        }

        printf("Outra tabuada? (S/s): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    return 0;
}
