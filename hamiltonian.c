#include <stdio.h>
#define MAX 10
int X[MAX];
int n = 4;
int G[MAX][MAX] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

void printsolution() {
  for(int i=0;i<n;i++)
    printf("%d\t", X[i]);
  printf("%d\n", X[0]);
}

void nextValue(int k) {
  while(1) {
    X[k] = (X[k]+1)%(n+1);
    if(X[k]==0)
      return;
    if(G[X[k-1]][X[k]]) {
      int i;
      for(i=0;i<k;i++) {
        if(X[i]==X[k])
          break;
      }
      if(i==k) {
        if(k<n-1 || (k==n-1 && G[X[k]][X[0]]!=0))
          return;
      }
    }
  }
}

void hamiltonian(int k) {
  while(1) {
    nextValue(k);
    if(X[k]==0)
      return;
    if(k==n-1)
      printsolution();
    else
      hamiltonian(k+1);
  }
}

void main() {
  for(int i=0;i<n;i++)
    X[i] = 0;

  X[0] = 0;
  printf("Hamiltonian cycles:\n");
  hamiltonian(1);
}