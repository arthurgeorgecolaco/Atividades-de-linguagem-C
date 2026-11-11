/* Funcoes - Questao 7: calcularMedia e verificarSituacao (aprovado se media >= 7) */
#include <stdio.h>

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

int verificarSituacao(float media) {
    if (media >= 7.0) {
        return 1;
    }
    return 0;
}

int main() {
    float a, b, c, media;

    printf("Digite as 3 notas: ");
    scanf("%f %f %f", &a, &b, &c);

    media = calcularMedia(a, b, c);
    printf("Media: %.2f\n", media);

    if (verificarSituacao(media)) {
        printf("Situacao: Aprovado\n");
    } else {
        printf("Situacao: Reprovado\n");
    }

    return 0;
}
