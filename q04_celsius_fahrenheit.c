/* Funcoes - Questao 4: funcao celsiusParaFahrenheit  F = (9 * C) / 5 + 32 */
#include <stdio.h>

float celsiusParaFahrenheit(float c) {
    return (9 * c) / 5 + 32;
}

int main() {
    float celsius;

    printf("Temperatura em Celsius: ");
    scanf("%f", &celsius);

    printf("Em Fahrenheit: %.2f\n", celsiusParaFahrenheit(celsius));
    return 0;
}
