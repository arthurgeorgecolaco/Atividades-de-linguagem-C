/*
 * Structs e arquivos - Atividade 5 (sistema eleitoral)
 * Struct Eleitor aninhada em Cedula, realloc para crescer a urna, gravacao em
 * urnas.bin e recuperacao rapida (fseek/ftell + um unico fread).
 */
#include <stdio.h>
#include <stdlib.h>

struct Eleitor {
    char titulo[12];
    int zona;
};

struct Cedula {
    struct Eleitor eleitor;
    int numero_voto;
};

struct Cedula *adicionarVoto(struct Cedula *urna, int *qtd, struct Cedula nova) {
    struct Cedula *tmp = (struct Cedula *) realloc(urna, (*qtd + 1) * sizeof(struct Cedula));
    if (tmp == NULL) {
        printf("Erro de alocacao!\n");
        return urna;
    }
    urna = tmp;
    urna[*qtd] = nova;
    (*qtd)++;
    return urna;
}

int salvarUrna(const char *nomeArq, struct Cedula *urna, int qtd) {
    FILE *arq = fopen(nomeArq, "wb");
    if (arq == NULL) {
        return 0;
    }
    fwrite(urna, sizeof(struct Cedula), qtd, arq);
    fclose(arq);
    return 1;
}

struct Cedula *recuperarUrna(const char *nomeArq, int *qtd) {
    FILE *arq = fopen(nomeArq, "rb");
    if (arq == NULL) {
        return NULL;
    }

    fseek(arq, 0, SEEK_END);
    long bytes = ftell(arq);
    rewind(arq);

    *qtd = bytes / sizeof(struct Cedula);

    struct Cedula *urna = (struct Cedula *) malloc(bytes);
    if (urna == NULL) {
        fclose(arq);
        return NULL;
    }

    fread(urna, sizeof(struct Cedula), *qtd, arq);
    fclose(arq);
    return urna;
}

int main() {
    struct Cedula *urna = NULL;
    int qtd = 0;
    char continuar;

    do {
        struct Cedula c;

        printf("\nTitulo do eleitor: ");
        scanf(" %11s", c.eleitor.titulo);
        printf("Zona: ");
        scanf("%d", &c.eleitor.zona);
        printf("Numero do voto: ");
        scanf("%d", &c.numero_voto);

        urna = adicionarVoto(urna, &qtd, c);

        printf("Registrar outro voto? (S/s para sim): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    if (salvarUrna("urnas.bin", urna, qtd)) {
        printf("\n%d votos salvos em urnas.bin\n", qtd);
    }
    free(urna);

    int total;
    struct Cedula *lida = recuperarUrna("urnas.bin", &total);
    if (lida == NULL) {
        printf("Erro ao recuperar a urna!\n");
        return 1;
    }

    printf("\n%-14s %-6s %s\n", "Titulo", "Zona", "Voto");
    for (int i = 0; i < total; i++) {
        printf("%-14s %-6d %d\n", lida[i].eleitor.titulo, lida[i].eleitor.zona, lida[i].numero_voto);
    }
    free(lida);

    return 0;
}
