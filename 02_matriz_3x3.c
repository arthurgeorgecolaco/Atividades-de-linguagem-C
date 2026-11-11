/*
 * Matrizes - Atividade 1
 * Gerar uma matriz 3x3 de inteiros e exibi-la com "-" entre os elementos
 * da mesma linha e uma nova linha entre as linhas.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int mat[3][3];

    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = rand() % 400;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", mat[i][j]);
            if (j < 2) {
                printf(" - ");
            }
        }
        printf("\n");
    }

    return 0;
}
