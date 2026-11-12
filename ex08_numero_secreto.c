/*
 * Laços - Exercicio 8: jogo do numero secreto entre 1 e 100, com dicas de
 * "maior" ou "menor", limite de 10 tentativas e contagem das tentativas.
 */
#include <stdio.h>

int main() {
    int secreto = 42, palpite, tentativas = 0, acertou = 0;

    while (tentativas < 10 && !acertou) {
        printf("Tentativa %d: ", tentativas + 1);
        scanf("%d", &palpite);
        tentativas++;

        if (palpite == secreto) {
            printf("Parabens! Voce acertou!\n");
            acertou = 1;
        } else if (palpite < secreto) {
            printf("O numero secreto e maior.\n");
        } else {
            printf("O numero secreto e menor.\n");
        }
    }

    if (!acertou) {
        printf("Fim de jogo! Era %d.\n", secreto);
    }
    printf("Tentativas realizadas: %d\n", tentativas);
    return 0;
}
