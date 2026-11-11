/*
 * Structs e arquivos - Atividade 4
 * Array dinamico de N professores, copia para buffer bruto com memcpy,
 * gravacao em folha.dat com um unico fwrite e leitura de volta com um unico
 * fread em um novo array dinamico.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Professor {
    int registro;
    int horas_aula;
};

struct Professor *lerProfessores(const char *nomeArq, int *qtd) {
    FILE *arq = fopen(nomeArq, "rb");
    if (arq == NULL) {
        return NULL;
    }

    fseek(arq, 0, SEEK_END);
    long bytes = ftell(arq);
    rewind(arq);

    *qtd = bytes / sizeof(struct Professor);

    struct Professor *lista = (struct Professor *) malloc(bytes);
    if (lista == NULL) {
        fclose(arq);
        return NULL;
    }

    fread(lista, sizeof(struct Professor), *qtd, arq);
    fclose(arq);
    return lista;
}

int main() {
    int n;
    struct Professor *profs;
    unsigned char *buffer;
    FILE *arq;

    do {
        printf("Quantos professores deseja cadastrar? ");
        scanf("%d", &n);
    } while (n <= 0);

    profs = (struct Professor *) malloc(n * sizeof(struct Professor));
    if (profs == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("--- Professor %d ---\n", i + 1);
        printf("Registro: ");
        scanf("%d", &profs[i].registro);
        printf("Horas-aula: ");
        scanf("%d", &profs[i].horas_aula);
    }

    buffer = (unsigned char *) malloc(n * sizeof(struct Professor));
    if (buffer == NULL) {
        printf("Erro de alocacao!\n");
        free(profs);
        return 1;
    }

    memcpy(buffer, profs, n * sizeof(struct Professor));

    arq = fopen("folha.dat", "wb");
    if (arq == NULL) {
        printf("Erro ao criar o arquivo!\n");
        free(profs);
        free(buffer);
        return 1;
    }
    fwrite(buffer, 1, n * sizeof(struct Professor), arq);
    fclose(arq);
    printf("\nfolha.dat gravado com %d professores.\n", n);

    int qtd;
    struct Professor *lidos = lerProfessores("folha.dat", &qtd);
    if (lidos == NULL) {
        printf("Erro ao ler o arquivo!\n");
    } else {
        printf("\n%-10s %s\n", "Registro", "Horas-aula");
        for (int i = 0; i < qtd; i++) {
            printf("%-10d %d\n", lidos[i].registro, lidos[i].horas_aula);
        }
        free(lidos);
    }

    free(profs);
    free(buffer);
    return 0;
}
