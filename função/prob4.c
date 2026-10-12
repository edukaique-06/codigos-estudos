#include <stdio.h>

void despertar(int l, int c, int m[l][c])
{
    int i,j;
    
    for(i=1;i<l - 1;i++)
    {
        for(j=1;j<c - 1;j++)
        {
            if(m[i][j] == 42)
            {
                if((m[i][j - 1] == 7 && m[i][j + 1] == 7) && (m[i - 1][j] == 7 && m[i + 1][j] == 7) && (m[i - 1][j - 1] == 7 && m[i - 1][j + 1] == 7 ) && (m[i + 1][j - 1] == 7 && m[i + 1][j + 1] == 7))
                {
                    printf("%d %d\n",i + 1, j + 1);
                    return;
                }
            }
        }
    }
    printf("0 0\n");
}

int main()
{
    int l,c;
    scanf("%d%d",&l,&c);

    int m[l][c];
    int i,j;

    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    despertar(l,c,m);
}
