#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    int id;
    char nome[50];
    int prioritario;
    struct Cliente* proximo;
} Cliente;

Cliente* criar_cliente(int id, const char* nome, int prioritario) {
    Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
    if (!novo) {
        exit(1);
    }
    novo->id = id;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->prioritario = prioritario;
    novo->proximo = NULL;
    return novo;
}

void inserir(Cliente** inicio, int id, const char* nome, int prioritario) {
    Cliente* novo = criar_cliente(id, nome, prioritario);

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    if (prioritario && !(*inicio)->prioritario) {
        novo->proximo = *inicio;
        *inicio = novo;
        return;
    }

    Cliente* atual = *inicio;
    if (prioritario) {
        while (atual->proximo != NULL && atual->proximo->prioritario) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    } else {
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void atender(Cliente** inicio) {
    if (*inicio == NULL) {
        return;
    }
    Cliente* atendido = *inicio;
    *inicio = (*inicio)->proximo;

    printf("--> Atendendo: [%s] %s (ID: %d)\n",
           atendido->prioritario ? "PRIORITARIO" : "COMUM",
           atendido->nome, atendido->id);

    free(atendido);
}

void imprimir_fila(Cliente* inicio) {
    printf("\n--- Estado Atual da Fila ---\n");
    if (!inicio) {
        printf("(Fila vazia)\n");
        return;
    }
    Cliente* atual = inicio;
    int pos = 1;
    while (atual != NULL) {
        printf("%d. [%s] %s (ID: %d)\n",
               pos++,
               atual->prioritario ? "PRIORITARIO" : "COMUM",
               atual->nome, atual->id);
        atual = atual->proximo;
    }
    printf("----------------------------\n\n");
}

void liberar_fila(Cliente** inicio) {
    Cliente* atual = *inicio;
    while (atual != NULL) {
        Cliente* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    *inicio = NULL;
}

int main() {
    Cliente* fila = NULL;

    inserir(&fila, 101, "Carlos Silva", 0);
    inserir(&fila, 102, "Mariana Souza", 0);
    imprimir_fila(fila);

    inserir(&fila, 103, "Dona Laura", 1);
    inserir(&fila, 104, "Sr. Joao", 1);
    imprimir_fila(fila);

    inserir(&fila, 105, "Pedro Lima", 0);
    imprimir_fila(fila);

    atender(&fila);
    atender(&fila);
    imprimir_fila(fila);

    liberar_fila(&fila);
}
