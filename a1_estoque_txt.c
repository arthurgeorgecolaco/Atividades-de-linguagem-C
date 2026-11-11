/*
 * Structs e arquivos - Atividade 1
 * Le 3 produtos (codigo, nome, preco) em um vetor de struct, salva em
 * estoque.txt (um produto por linha), reabre para leitura e exibe organizado.
 */
#include <stdio.h>

#define N 3

struct Produto {
    int codigo;
    char nome[50];
    float preco;
};

int main() {
    struct Produto produtos[N];
    FILE *arq;

    for (int i = 0; i < N; i++) {
        printf("--- Produto %d ---\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        printf("Nome: ");
        scanf(" %49[^\n]", produtos[i].nome);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
    }

    arq = fopen("estoque.txt", "w");
    if (arq == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        fprintf(arq, "%d;%s;%.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
    fclose(arq);

    arq = fopen("estoque.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    struct Produto p;
    printf("\n%-8s %-25s %10s\n", "Codigo", "Nome", "Preco");
    printf("-------------------------------------------\n");
    while (fscanf(arq, "%d;%49[^;];%f\n", &p.codigo, p.nome, &p.preco) == 3) {
        printf("%-8d %-25s %10.2f\n", p.codigo, p.nome, p.preco);
    }
    fclose(arq);

    return 0;
}
