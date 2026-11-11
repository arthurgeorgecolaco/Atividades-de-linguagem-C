/*
 * Desafio 1 - Sorteio beneficente.
 * Le 12 inteiros, conta as ocorrencias de cada numero distinto.
 * Ocorrencias impares: o numero e a quantidade a comprar -> cadastra produto.
 * Ocorrencias pares: numero vai para um segundo vetor, ordenado decrescente.
 * Produtos exibidos em ordem alfabetica.
 */
#include <stdio.h>
#include <string.h>

#define N 12

int main() {
    int vet[N];
    int distintos[N], ocorrencias[N], qtdDistintos = 0;
    int pares[N], qtdPares = 0;
    char nomes[N][50];
    float precos[N];
    int quantidades[N], qtdProdutos = 0;

    for (int i = 0; i < N; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    /* a) contagem de ocorrencias */
    for (int i = 0; i < N; i++) {
        int encontrado = 0;
        for (int j = 0; j < qtdDistintos; j++) {
            if (distintos[j] == vet[i]) {
                ocorrencias[j]++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            distintos[qtdDistintos] = vet[i];
            ocorrencias[qtdDistintos] = 1;
            qtdDistintos++;
        }
    }

    /* impares -> cadastro de produto; pares -> vetor de pares */
    for (int j = 0; j < qtdDistintos; j++) {
        if (ocorrencias[j] % 2 == 0) {
            pares[qtdPares] = distintos[j];
            qtdPares++;
        } else {
            printf("\nO numero %d aparece %d vez(es): comprar %d unidades.\n",
                   distintos[j], ocorrencias[j], distintos[j]);
            printf("Nome do produto: ");
            scanf(" %49[^\n]", nomes[qtdProdutos]);
            printf("Preco unitario: ");
            scanf("%f", &precos[qtdProdutos]);
            quantidades[qtdProdutos] = distintos[j];
            qtdProdutos++;
        }
    }

    /* pares em ordem decrescente */
    for (int i = 0; i < qtdPares - 1; i++) {
        for (int j = 0; j < qtdPares - 1 - i; j++) {
            if (pares[j] < pares[j + 1]) {
                int aux = pares[j];
                pares[j] = pares[j + 1];
                pares[j + 1] = aux;
            }
        }
    }

    /* produtos em ordem alfabetica (troca os tres vetores juntos) */
    for (int i = 0; i < qtdProdutos - 1; i++) {
        for (int j = 0; j < qtdProdutos - 1 - i; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                char auxNome[50];
                float auxPreco;
                int auxQtd;

                strcpy(auxNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], auxNome);

                auxPreco = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = auxPreco;

                auxQtd = quantidades[j];
                quantidades[j] = quantidades[j + 1];
                quantidades[j + 1] = auxQtd;
            }
        }
    }

    printf("\n=== Numeros informados ===\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vet[i]);
    }

    printf("\n\n=== Numeros distintos e ocorrencias ===\n");
    for (int j = 0; j < qtdDistintos; j++) {
        printf("%d aparece %d vez(es)\n", distintos[j], ocorrencias[j]);
    }

    printf("\n=== Produtos para compra (ordem alfabetica) ===\n");
    for (int i = 0; i < qtdProdutos; i++) {
        printf("%s - quantidade: %d - preco: R$ %.2f\n",
               nomes[i], quantidades[i], precos[i]);
    }

    printf("\n=== Numeros com ocorrencias pares (decrescente) ===\n");
    for (int i = 0; i < qtdPares; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");

    return 0;
}
