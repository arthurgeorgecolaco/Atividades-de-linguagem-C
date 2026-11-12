/*
 * Laços - Exercicio 4: le inteiros ate o usuario digitar 0 e mostra a soma e
 * a quantidade de positivos e de negativos (o zero nao conta).
 */
#include <stdio.h>

int main() {
    int num, qtdPos = 0, qtdNeg = 0, somaPos = 0, somaNeg = 0;

    do {
        printf("Numero (0 para encerrar): ");
        scanf("%d", &num);

        if (num > 0) {
            somaPos += num;
            qtdPos++;
        } else if (num < 0) {
            somaNeg += num;
            qtdNeg++;
        }
    } while (num != 0);

    printf("Soma positivos: %d\n", somaPos);
    printf("Soma negativos: %d\n", somaNeg);
    printf("Qtd positivos: %d\n", qtdPos);
    printf("Qtd negativos: %d\n", qtdNeg);
    return 0;
}
