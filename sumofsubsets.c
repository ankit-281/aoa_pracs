#include <stdio.h>

#define max 10

int X[max], m, w[max];

void sortWeights(int w[], int n) {
  for(int i=0;i<n-1;i++) {
    for(int j=0;j<n-i-1;j++) {
      if(w[j]>w[j+1]) {
        int temp = w[j];
        w[j] = w[j+1];
        w[j+1] = temp;
      }
    }
  }
}

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

  sortWeights(w, n);

  printf("Subsets whose sum is %d are:\n", m);
  sumofsubset(0, 0, r);
}