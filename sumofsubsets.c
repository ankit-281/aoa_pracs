#include <stdio.h>

#define max 10

int X[max], m, w[max];

void sumofsubset(int s, int k, int r) {
  X[k] = 1;
  if(s+w[k]==m) {
    for(int i=0;i<=k;i++) {
      if(X[i]==1)
        printf("%d ", w[i]);
    }
    printf("\n");
  }
  else if(s+w[k]+w[k+1]<=m)
    sumofsubset(s+w[k], k+1, r-w[k]);
  if(s+w[k+1]<=m && s+r-w[k]>=m) {
    X[k] = 0;
    sumofsubset(s, k+1, r-w[k]);
  }
}

void main() {
  int r = 0, n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  printf("Enter the weights: ");
  for (int i = 0; i < n; i++) {
      scanf("%d", &w[i]);
      r += w[i];
  }

  printf("Enter the target sum: ");
  scanf("%d", &m);

  printf("Subsets whose sum is %d are:\n", m);
  sumofsubset(0, 0, r);
}