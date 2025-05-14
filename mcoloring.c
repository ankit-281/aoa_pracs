#include <stdio.h>
#define MAX 10
int X[MAX];
int n = 4;
int m = 3;
int G[MAX][MAX] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

void printsolution() {
  for(int i=0;i<n;i++)
    printf("%d\t", X[i]);
  printf("\n");
}

void nextValue(int k) {
  while (1)
  {
    X[k] = (X[k]+1)%(m+1);
    if(X[k]==0)
      return;
    int i;
    for(i=0;i<n;i++) {
      if(G[i][k]!=0 && X[i]==X[k])
        break;
    }
    if(i==n)
      return;
  }
}

void mcoloring(int k) {
  while(1) {
    nextValue(k);
    if(X[k]==0)
      return;
    if(k==n-1)
      printsolution();
    else
      mcoloring(k+1);
  }
}

void main() {
  for(int i=0;i<n;i++)
    X[i] = 0;
  printf("Coloring ways:\n");
  mcoloring(0);
}