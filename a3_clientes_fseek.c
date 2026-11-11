/*
 * Structs e arquivos - Atividade 3
 * Atualiza o saldo de um cliente em clientes.bin (modo "rb+") usando fseek
 * para voltar um registro e sobrescreve-lo.
 * Valor positivo = deposito, negativo = saque.
 * Use criar_clientes.c para gerar um clientes.bin de teste.
 */
#include <stdio.h>

struct Cliente {
    int conta_corrente;
    char nome[50];
    float saldo;
};

int main() {
    struct Cliente c;
    FILE *arq;
    int conta, achou = 0;
    float valor;

    printf("Numero da conta corrente: ");
    scanf("%d", &conta);
    printf("Valor (positivo = deposito, negativo = saque): ");
    scanf("%f", &valor);

    arq = fopen("clientes.bin", "rb+");
    if (arq == NULL) {
        printf("Erro ao abrir clientes.bin!\n");
        return 1;
    }

    while (fread(&c, sizeof(struct Cliente), 1, arq) == 1) {
        if (c.conta_corrente == conta) {
            achou = 1;

            if (valor < 0 && c.saldo + valor < 0) {
                printf("Saldo insuficiente! Saldo atual: %.2f\n", c.saldo);
                break;
            }

            c.saldo += valor;

            fseek(arq, -(long) sizeof(struct Cliente), SEEK_CUR);
            fwrite(&c, sizeof(struct Cliente), 1, arq);

            printf("Operacao realizada. Novo saldo de %s: %.2f\n", c.nome, c.saldo);
            break;
        }
    }

    if (!achou) {
        printf("Conta %d nao encontrada.\n", conta);
    }

    fclose(arq);
    return 0;
}
