/* Auxiliar da Atividade 3: cria um clientes.bin com 3 clientes de teste. */
#include <stdio.h>

struct Cliente {
    int conta_corrente;
    char nome[50];
    float saldo;
};

int main() {
    struct Cliente lista[3] = {
        {1001, "Ana", 500.00},
        {1002, "Bruno", 1200.50},
        {1003, "Carlos", 80.00}
    };
    FILE *arq = fopen("clientes.bin", "wb");
    if (arq == NULL) {
        printf("Erro ao criar clientes.bin!\n");
        return 1;
    }
    fwrite(lista, sizeof(struct Cliente), 3, arq);
    fclose(arq);
    printf("clientes.bin criado com 3 clientes.\n");
    return 0;
}
