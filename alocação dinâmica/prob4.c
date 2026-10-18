#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10; // O problema trabalha com um vetor de 10 posições
    
    // Alocação dinâmica de memória para 10 inteiros
    int *X = (int *) malloc(n * sizeof(int));
    
    // Verifica se a memória foi alocada com sucesso
    if (X == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Leitura dos valores
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
        
        // Substitui valores nulos ou negativos por 1
        if (X[i] <= 0) {
            X[i] = 1;
        }
    }

    // Impressão do resultado formatado conforme o Beecrowd exige
    for (int i = 0; i < n; i++) {
        printf("X[%d] = %d\n", i, X[i]);
    }

    // Liberação da memória alocada dinamicamente
    free(X);
}
