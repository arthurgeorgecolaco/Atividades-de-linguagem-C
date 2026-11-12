/*
 * Matriz - le 3 notas de 3 alunos e calcula a media de cada um.
 * As notas ficam em uma matriz 3x4: colunas 0 a 2 = notas, coluna 3 = media.
 */
#include <stdio.h>

int main() {
    float mat[3][4], soma;

    for (int i = 0; i < 3; i++) {
        soma = 0;
        for (int j = 0; j < 3; j++) {
            printf("Aluno %d - nota %d: ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
            soma += mat[i][j];
        }
        mat[i][3] = soma / 3;
    }

    printf("\n        nota1 nota2 nota3 media\n");
    for (int i = 0; i < 3; i++) {
        printf("Aluno%d", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%6.1f", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
