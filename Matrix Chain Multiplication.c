#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void brackets(int s[][50], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");
    brackets(s,i, s[i][j]);
    brackets(s,s[i][j] + 1, j);
    printf(")");
}

void main()
{
	int d[50], diff, n, c[50][50], s[50][50], i, j, k;
	printf("Enter the number of matrices: ");
	scanf("%d",&n);
	printf("Enter d matrix: ");
	for(i=0; i<=n; i++)
		scanf("%d",&d[i]);
	for(i=0; i<=n; i++)
		for(j=0; j<=n; j++)
			c[i][j] = 0;
	for(diff=1; diff<n; diff++)
	{
		for(i=1; i<n-diff+1; i++)
		{
			j = i+diff;
			c[i][j] = INT_MAX;
			for(k=i; k<j; k++)
				if(c[i][k] + c[k+1][j] + d[i-1]*d[k]*d[j] < c[i][j])
				{
					c[i][j] = c[i][k] + c[k+1][j] + d[i-1]*d[k]*d[j];
					s[i][j] = k;
				}
		}
	}
	printf("Cost matrix: \n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
	printf("k matrix: \n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
			printf("%d\t",s[i][j]);
		printf("\n");
	}

	brackets(s,1,n);
}