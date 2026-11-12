/*
 * Vamos Praticar 4 - Meta diaria de passos.
 * Le os passos de cada hora ate o total atingir ou ultrapassar 10.000 e
 * informa quantas horas foram necessarias.
 */
#include <stdio.h>

int main() {
    int passos, total = 0, horas = 0;

    while (total < 10000) {
        printf("Passos na hora %d: ", horas + 1);
        scanf("%d", &passos);
        total += passos;
        horas++;
    }

    printf("Meta atingida! Total: %d\n", total);
    printf("Horas necessarias: %d\n", horas);
    return 0;
}
