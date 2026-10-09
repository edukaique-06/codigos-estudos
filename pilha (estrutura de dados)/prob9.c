#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *pilha;
    int tamanho;
    int topo;
    int qntd;
} Pilha;

Pilha *CriarPilha(int tam)
{
    Pilha *p = malloc(sizeof(Pilha));
    p->pilha = malloc(tam * sizeof(char));
    p->tamanho = tam;
    p->topo = -1;
    p->qntd = 0;
    return p;
}

void Push(Pilha *p, char caracter)
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
            p->pilha[p->topo] = caracter;
            p->qntd++;
        }
    }
}

char Pop(Pilha *p)
{
    char c = '\0';
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
    char num[100];
    fgets(num, sizeof(num), stdin);
    num[strcspn(num, "\n")] = '\0';

    int k;
    scanf("%d", &k);

    int len = strlen(num);
    Pilha *p = CriarPilha(len);

    for (int i = 0; i < len; i++)
    {
        char c = num[i];
        while (p->topo != -1 && k > 0 && p->pilha[p->topo] > c)
        {
            Pop(p);
            k--;
        }
        Push(p, c);
    }

    while (k > 0 && p->topo != -1)
    {
        Pop(p);
        k--;
    }

    int i = 0;
    while (i <= p->topo && p->pilha[i] == '0')
    {
        i++;
    }

    if (i > p->topo)
    {
        printf("0\n");
    }
    else
    {
        for (int j = i; j <= p->topo; j++)
        {
            printf("%c", p->pilha[j]);
        }
        printf("\n");
    }

    free(p->pilha);
    free(p);
}
