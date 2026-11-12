/*
 * Vetor - estoque de 10 produtos: mostra a quantidade de cada um, os de
 * estoque baixo (< 5), os esgotados (= 0), quantos tem mais de 20 unidades e
 * qual tem a maior quantidade.
 */
#include <stdio.h>

int main() {
    int qtd[10], acima20 = 0, maior = 0;

    for (int i = 0; i < 10; i++) {
        printf("Quantidade do produto %d: ", i + 1);
        scanf("%d", &qtd[i]);
    }

    printf("\nQuantidades:\n");
    for (int i = 0; i < 10; i++) {
        printf("Produto %d: %d\n", i + 1, qtd[i]);
    }

    printf("\nEstoque baixo (< 5):\n");
    for (int i = 0; i < 10; i++) {
        if (qtd[i] < 5) {
            printf("Produto %d\n", i + 1);
        }
    }

    printf("\nEsgotados:\n");
    for (int i = 0; i < 10; i++) {
        if (qtd[i] == 0) {
            printf("Produto %d\n", i + 1);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (qtd[i] > 20) {
            acima20++;
        }
        if (qtd[i] > qtd[maior]) {
            maior = i;
        }
    }

    printf("\nMais de 20 unidades: %d produtos\n", acima20);
    printf("Maior estoque: produto %d (%d un.)\n", maior + 1, qtd[maior]);
    return 0;
}
