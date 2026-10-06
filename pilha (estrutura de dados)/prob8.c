#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *pilha;
    int tamanho;
    int topo;
    int qntd;
} Pilha;

Pilha *CriarPilha(int tam)
{
    Pilha *p = malloc(sizeof(Pilha));
    p->pilha = malloc(tam * sizeof(int));
    p->tamanho = tam;
    p->topo = -1;
    p->qntd = 0;
    return p;
}

void Push(Pilha *p, int valor)
{
    if (p == NULL)
    {
        printf("Pilha Inexistente\n");
    }
    else
    {
        if (p->qntd == p->tamanho)
        {
            printf("Stack Overflow\n");
        }
        else
        {
            p->topo++;
            p->pilha[p->topo] = valor;
            p->qntd++;
        }
    }
}

int Pop(Pilha *p)
{
    int c = -1;
    if (p == NULL)
    {
        printf("Pilha Inexistente\n");
    }
    else
    {
        if (p->qntd == 0)
        {
            printf("Stack Underflow\n");
        }
        else
        {
            c = p->pilha[p->topo];
            p->topo--;
            p->qntd--;
            return c;
        }
    }
    return c;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *alturas = malloc(n * sizeof(int));
    for (int k = 0; k < n; k++)
    {
        scanf("%d", &alturas[k]);
    }

    Pilha *p = CriarPilha(n + 1);
    int area_maxima = 0;
    int i = 0;

    while (i < n)
    {
        if (p->topo == -1 || alturas[i] >= alturas[p->pilha[p->topo]])
        {
            Push(p, i);
            i++;
        }
        else
        {
            int topo_idx = Pop(p);
            int largura = (p->topo == -1) ? i : (i - p->pilha[p->topo] - 1);
            int area = alturas[topo_idx] * largura;
            if (area > area_maxima)
            {
                area_maxima = area;
            }
        }
    }

    while (p->topo != -1)
    {
        int topo_idx = Pop(p);
        int largura = (p->topo == -1) ? i : (i - p->pilha[p->topo] - 1);
        int area = alturas[topo_idx] * largura;
        if (area > area_maxima)
        {
            area_maxima = area;
        }
    }

    printf("%d\n", area_maxima);

    free(alturas);
    free(p->pilha);
    free(p);
}
