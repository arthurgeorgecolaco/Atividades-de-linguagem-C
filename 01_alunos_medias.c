/*
 * Vetores - Atividade 1
 * Ler o nome e a media de 30 alunos usando vetores e exibir a lista.
 */
#include <stdio.h>

#define N 30

int main() {
    char nomes[N][50];
    float medias[N];

    for (int i = 0; i < N; i++) {
        printf("Nome do aluno %d: ", i + 1);
        scanf(" %49[^\n]", nomes[i]);

        printf("Media de %s: ", nomes[i]);
        scanf("%f", &medias[i]);
    }

    printf("\n--- Lista de alunos ---\n");
    for (int i = 0; i < N; i++) {
        printf("%2d. %-30s Media: %.2f\n", i + 1, nomes[i], medias[i]);
    }

    return 0;
}
