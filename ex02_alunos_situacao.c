/*
 * Laços - Exercicio 2: le 3 notas de varios alunos enquanto o usuario desejar.
 * Aprovado (media >= 7), Recuperacao (5 a 6,9) ou Reprovado (< 5).
 * No final mostra quantos ficaram em cada situacao.
 */
#include <stdio.h>

int main() {
    float n1, n2, n3, media;
    int aprov = 0, recup = 0, reprov = 0;
    char continuar;

    do {
        printf("Digite as 3 notas: ");
        scanf("%f %f %f", &n1, &n2, &n3);
        media = (n1 + n2 + n3) / 3;

        if (media >= 7) {
            printf("Aprovado\n");
            aprov++;
        } else if (media >= 5) {
            printf("Recuperacao\n");
            recup++;
        } else {
            printf("Reprovado\n");
            reprov++;
        }

        printf("Outro aluno? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("Aprovados: %d\n", aprov);
    printf("Recuperacao: %d\n", recup);
    printf("Reprovados: %d\n", reprov);
    return 0;
}
