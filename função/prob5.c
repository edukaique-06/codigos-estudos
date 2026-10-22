#include <stdio.h>

#define N 4 // Número de equações e variáveis

// Função para exibir a matriz na tela
void imprimirMatriz(float matriz[N][N+1]) {
    int i, j;
    for (i = 0; i < N; i++) {
        printf("[ ");
        for (j = 0; j <= N; j++) {
            printf("%8.2f ", matriz[i][j]);
            if (j == N - 1) printf(" | ");
        }
        printf("]\n");
    }
    printf("\n");
}

// Função para fazer o escalonamento da matriz
void escalonar(float matriz[N][N+1]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        // Pivoteamento parcial simples para evitar divisão por zero
        int maxRow = i;
        for (k = i + 1; k < N; k++) {
            if (matriz[k][i] > matriz[maxRow][i] || -matriz[k][i] > matriz[maxRow][i]) {
                maxRow = k;
            }
        }

        // Troca de linhas se necessário
        if (maxRow != i) {
            for (k = 0; k <= N; k++) {
                float temp = matriz[i][k];
                matriz[i][k] = matriz[maxRow][k];
                matriz[maxRow][k] = temp;
            }
        }

        // Verifica se o pivô é zero
        if (matriz[i][i] == 0) {
            printf("Sistema sem solucao unica (pivo zero).\n");
            return;
        }

        // Zera os elementos abaixo da diagonal principal
        for (k = i + 1; k < N; k++) {
            float fator = matriz[k][i] / matriz[i][i];
            for (j = i; j <= N; j++) {
                matriz[k][j] -= fator * matriz[i][j];
            }
        }
    }
}

// Função para calcular os valores de x por substituição retroativa
void substituicaoRetroativa(float matriz[N][N+1], float resultado[N]) {
    int i, j;
    for (i = N - 1; i >= 0; i--) {
        resultado[i] = matriz[i][N];
        for (j = i + 1; j < N; j++) {
            resultado[i] -= matriz[i][j] * resultado[j];
        }
        resultado[i] /= matriz[i][i];
    }
}

int main() {
    // Matriz aumentada preenchida com os dados do exercício anterior
    float matriz[N][N+1] = {
        {1, 1, 5, 2, 14},
        {1, 10, 2, 4, 19},
        {20, 6, 4, 7, 41},
        {5, 6, 5, 15, 54}
    };

    printf("--- Matriz Inicial ---\n");
    imprimirMatriz(matriz);

    // Executa o escalonamento
    escalonar(matriz);

    printf("--- Matriz Escalonada ---\n");
    imprimirMatriz(matriz);

    // Calcula as soluções
    float resultado[N];
    substituicaoRetroativa(matriz, resultado);

    printf("--- Solucoes Encontradas ---\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.4f\n", i + 1, resultado[i]);
    }
}
