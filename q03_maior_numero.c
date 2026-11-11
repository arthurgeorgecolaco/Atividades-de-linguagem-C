/* Funcoes - Questao 3: funcao maiorNumero */
#include <stdio.h>

int maiorNumero(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    int x, y;

    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);

    printf("Maior: %d\n", maiorNumero(x, y));
    return 0;
}
