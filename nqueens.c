#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX 10
int X[MAX];

bool place(int row, int col) {
  for(int i=0;i<row;i++) {
    if(X[i]==col || abs(X[i]-col)==abs(row-i))
      return false;
  }
  return true;
}

void nqueens(int n, int row) {
  for(int col=0;col<n;col++) {
    if(place(row, col)) {
      X[row] = col;
      if(row==n-1) {
        for(int i=0;i<n;i++)
          printf("Q%d:%d\t", i+1, X[i]+1);
        printf("\n");
      }
      else
        nqueens(n,row+1);
    }
  }  
}

void main() {
  int n;
  printf("Enter no. of queens: ");
  scanf("%d", &n);
  nqueens(n, 0);
}