#include <stdio.h>

#define MAX 10

int max(int a, int b) {
  return (a>b)?a:b;
}

void knapsack(int w[MAX], int p[MAX], int n, int c) {
  int dp[MAX][MAX];
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=c;j++) {
      dp[i][j] = 0;
    }
  }
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=c;j++) {
      if(w[i-1]<=j) {
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+p[i-1]);
      }
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=c;j++) {
      printf("%d\t", dp[i][j]);
    }
    printf("\n");
  }
  printf("\nMaximum Profit: %d\n", dp[n][c]);

  printf("Items included: \n");
  int i=n, j=c;
  while(i>0 && j>0) {
    if(dp[i][j]!=dp[i-1][j]) {
      printf("%d\t", i);
      j-=w[i-1];
    }
    i--;
  }
}

void main() {
  int n, w[MAX], p[MAX], c;
  printf("Enter no. of elements: ");
  scanf("%d", &n);
  printf("Enter weights:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &w[i]);
  printf("Enter profits:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &p[i]);
  printf("Enter knapsack capacity: ");
    scanf("%d", &c);

  knapsack(w, p, n, c);
}