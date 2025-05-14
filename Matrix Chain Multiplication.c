#include <stdio.h>
#include <limits.h>

#define max 100

int C[max][max];
int K[max][max];

void brackets(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");
    brackets(i, K[i][j]);
    brackets(K[i][j] + 1, j);
    printf(")");
}

int main()
{
    int n, q, min;
    printf("Enter the no of dimensions: ");
    scanf("%d", &n);

    int d[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }

    for (int i = 1; i < n; i++)
        C[i][i] = 0;

    for (int r = 1; r < n - 1; r++) 
    {
        for (int i = 1; i < n - r; i++) 
        {
            int j = i + r; 
            min = INT_MAX;
            for (int k = i; k < j; k++)  
            {
                q = C[i][k] + C[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < min)
                {
                    min = q;
                    K[i][j] = k;
                }
            }
            C[i][j] = min;
        }
    }

    printf("Cost table:\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    printf("\nK-Index Table:\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf("%d\t", K[i][j]);
        }
        printf("\n");
    }

    printf("Multiplication order = ");
    brackets(1, n - 1);
    printf("\n");

    return 0;
}