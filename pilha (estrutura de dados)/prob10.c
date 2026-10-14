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

    int *arr = malloc(n * sizeof(int));
    for (int k = 0; k < n; k++)
    {
        scanf("%d", &arr[k]);
    }

    int max_pessoas = 0;

    for (int i = 0; i < n; i++)
    {
        int visiveis = 1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                visiveis++;
            }
            else
            {
                visiveis++;
                break;
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                visiveis++;
            }
            else
            {
                visiveis++;
                break;
            }
        }

        if (visiveis > max_pessoas)
        {
            max_pessoas = visiveis;
        }
    }

    Pilha *p = CriarPilha(n);
    Push(p, max_pessoas);
    printf("%d\n", Pop(p));

    free(arr);
    free(p->pilha);
    free(p);
}
