#include <stdio.h>
#include <stdlib.h>

#define MAX 105

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int qtd;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}

int estaVazia(Fila *f) {
    return f->qtd == 0;
}

void enfileirar(Fila *f, int valor) {
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->qtd++;
}

int desenfileirar(Fila *f) {
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->qtd--;
    return valor;
}

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        Fila cartas;
        inicializarFila(&cartas);

        for (int i = 1; i <= n; i++) {
            enfileirar(&cartas, i);
        }

        printf("Discarded cards:");
        int primeiroDescarte = 1;

        while (cartas.qtd > 1) {
            int descartada = desenfileirar(&cartas);
            if (primeiroDescarte) {
                printf(" %d", descartada);
                primeiroDescarte = 0;
            } else {
                printf(", %d", descartada);
            }

            // Move a próxima carta para a base
            int mover = desenfileirar(&cartas);
            enfileirar(&cartas, mover);
        }

        printf("\nRemaining card: %d\n", desenfileirar(&cartas));
    }
}
