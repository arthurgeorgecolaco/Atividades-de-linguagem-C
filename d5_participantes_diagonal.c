/*
 * Desafio 5 - Quatro participantes: ID unico (baseado no fatorial da idade),
 * matriz de valores, media ponderada, diagonal de um retangulo (Pitagoras) e
 * classificacao final em ordem alfabetica.
 * Compilar com: gcc d5_participantes_diagonal.c -o d5 -lm
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define P 4
#define MAXV 20

double fatorial(int n) {
    double f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

int idExiste(double ids[], int n, double id) {
    for (int i = 0; i < n; i++) {
        if (ids[i] == id) {
            return 1;
        }
    }
    return 0;
}

double calcularID(int idade, double ids[], int n) {
    double id = fatorial(idade) / 2;
    int base = idade / 2;

    while (idExiste(ids, n, id)) {
        id = fatorial(base);
        base++;
    }
    return id;
}

double mediaPonderada(float v[], int n) {
    double soma = 0, pesos = 0;
    for (int k = 0; k < n; k++) {
        soma += v[k] * (k + 1);
        pesos += (k + 1);
    }
    return soma / pesos;
}

int main() {
    char nomes[P][50];
    int idades[P];
    double ids[P];
    float valores[P][MAXV];
    int qtd;

    float lado1 = 0, lado2 = 0;
    int achados = 0;

    for (int i = 0; i < P; i++) {
        printf("Nome do participante %d: ", i + 1);
        scanf(" %49[^\n]", nomes[i]);
        printf("Idade de %s: ", nomes[i]);
        scanf("%d", &idades[i]);

        ids[i] = calcularID(idades[i], ids, i);
    }

    do {
        printf("\nQuantos valores por participante (1 a %d)? ", MAXV);
        scanf("%d", &qtd);
    } while (qtd < 1 || qtd > MAXV);

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < qtd; j++) {
            printf("Valor %d de %s: ", j + 1, nomes[i]);
            scanf("%f", &valores[i][j]);

            if (valores[i][j] >= 0 && achados < 2) {
                if (achados == 0) {
                    lado1 = valores[i][j];
                } else {
                    lado2 = valores[i][j];
                }
                achados++;
            }
        }
    }

    /* ordem alfabetica: troca nome, idade, ID e a linha da matriz juntos */
    for (int i = 0; i < P - 1; i++) {
        for (int j = 0; j < P - 1 - i; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                char auxNome[50];
                int auxIdade;
                double auxId;

                strcpy(auxNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], auxNome);

                auxIdade = idades[j];
                idades[j] = idades[j + 1];
                idades[j + 1] = auxIdade;

                auxId = ids[j];
                ids[j] = ids[j + 1];
                ids[j + 1] = auxId;

                for (int k = 0; k < qtd; k++) {
                    float aux = valores[j][k];
                    valores[j][k] = valores[j + 1][k];
                    valores[j + 1][k] = aux;
                }
            }
        }
    }

    if (achados < 2) {
        printf("\nNao foi possivel calcular a diagonal.\n");
        return 0;
    }
    double diagonal = sqrt(lado1 * lado1 + lado2 * lado2);

    printf("\n========== CLASSIFICACAO FINAL ==========\n\n");
    for (int i = 0; i < P; i++) {
        double media = mediaPonderada(valores[i], qtd);

        printf("%-10s ........ ", nomes[i]);
        if (fabs(media - diagonal) < 1e-9) {
            printf("SOBRE A DIAGONAL\n");
        } else if (media > diagonal) {
            printf("ACIMA DA DIAGONAL\n");
        } else {
            printf("ABAIXO DA DIAGONAL\n");
        }
    }
    printf("\n=========================================\n");

    return 0;
}
