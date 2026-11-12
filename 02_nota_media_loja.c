/*
 * Vamos Praticar 3 - Nota media de atendimento da loja.
 * Le 10 notas (0 a 10), calcula a media e alerta se for menor que 7.
 */
#include <stdio.h>

int main() {
    float nota, soma = 0, media;

    for (int i = 1; i <= 10; i++) {
        printf("Nota do cliente %d: ", i);
        scanf("%f", &nota);
        soma += nota;
    }

    media = soma / 10;
    printf("Media: %.2f\n", media);

    if (media < 7) {
        printf("ALERTA: media abaixo de 7!\n");
    }
    return 0;
}
