/*
 * Funcoes - Questao 10: vendas de cinco dias.
 * calcularTotal, calcularMedia e contarVendasAcimaDaMedia recebem o vetor.
 */
#include <stdio.h>

#define DIAS 5

float calcularTotal(float vendas[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += vendas[i];
    }
    return total;
}

float calcularMedia(float vendas[], int n) {
    return calcularTotal(vendas, n) / n;
}

int contarVendasAcimaDaMedia(float vendas[], int n, float media) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (vendas[i] > media) {
            cont++;
        }
    }
    return cont;
}

int main() {
    float vendas[DIAS], total, media;
    int acima;

    for (int i = 0; i < DIAS; i++) {
        printf("Vendas do dia %d: ", i + 1);
        scanf("%f", &vendas[i]);
    }

    total = calcularTotal(vendas, DIAS);
    media = calcularMedia(vendas, DIAS);
    acima = contarVendasAcimaDaMedia(vendas, DIAS, media);

    printf("\nTotal vendido: %.2f\n", total);
    printf("Media diaria: %.2f\n", media);
    printf("Dias acima da media: %d\n", acima);

    return 0;
}
