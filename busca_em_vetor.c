/*
 * Vetor - le 10 inteiros e busca um numero: informa se foi encontrado,
 * quantas vezes aparece e em quais posicoes (indices a partir de 0).
 */
#include <stdio.h>

int main() {
    int vet[10], busca, vezes = 0;

    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    printf("Digite um numero: ");
    scanf("%d", &busca);

    for (int i = 0; i < 10; i++) {
        if (vet[i] == busca) {
            vezes++;
        }
    }

    if (vezes == 0) {
        printf("Numero nao encontrado.\n");
    } else {
        printf("Encontrado %d vezes.\nPosicoes: ", vezes);
        for (int i = 0; i < 10; i++) {
            if (vet[i] == busca) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}
