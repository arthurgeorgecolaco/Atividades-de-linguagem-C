/*
 * Vamos Praticar 1 - Consumo de agua do condominio.
 * Le o consumo mensal (m3) de 5 moradores, informa se esta dentro da media
 * (ate 20 m3) ou acima e mostra o consumo medio geral.
 */
#include <stdio.h>

int main() {
    float consumo, soma = 0;

    for (int i = 1; i <= 5; i++) {
        printf("Consumo do morador %d: ", i);
        scanf("%f", &consumo);
        soma += consumo;

        if (consumo <= 20) {
            printf("Dentro da media.\n");
        } else {
            printf("Acima da media.\n");
        }
    }

    printf("Consumo medio: %.2f\n", soma / 5);
    return 0;
}
