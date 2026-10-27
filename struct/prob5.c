#include <stdio.h>

// Definição da struct para o Aluno
typedef struct {
    char nome[51];
    float n1;
    float n2;
    float media;
} Aluno;

int main() {
    int n, i;
    
    // Leitura do número de casos de teste / alunos
    if (scanf("%d", &n) != 1) return 0;
    
    // Vetor de structs para armazenar os dados
    Aluno turma[n];
    
    // Lendo os dados de cada aluno
    for (i = 0; i < n; i++) {
        scanf("%s %f %f", turma[i].nome, &turma[i].n1, &turma[i].n2);
        
        // Calculando a média aritmética
        turma[i].media = (turma[i].n1 + turma[i].n2) / 2.0;
    }
    
    // Exibindo a saída formatada de acordo com o problema
    for (i = 0; i < n; i++) {
        printf("%s - Media: %.2f - ", turma[i].nome, turma[i].media);
        
        if (turma[i].media >= 6.0) {
            printf("APROVADO\n");
        } else {
            printf("REPROVADO\n");
        }
    }
  
}
