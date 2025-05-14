#include <stdio.h>
int partition(int a[], int low, int high) {
  int pivot = a[high];
  int j=low;
  for(int i=low;i<high;i++) {
    if(a[i]<=pivot) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      j++;
    }
  }
  int temp = a[high];
  a[high] = a[j];
  a[j] = temp;
  return j;
}

void quicksort(int a[], int low, int high) {
  if(low<high) {
    int pi=partition(a, low, high);
    quicksort(a, low, pi-1);
    quicksort(a, pi+1, high);
  }
}

void main() {
  int n, a[10], i, j, imin, temp;
  printf("Enter no. of elements of array: ");
  scanf("%d", &n);
  printf("Enter elements of array:\n");
  for(i=0;i<n;i++) {
    scanf("%d", &a[i]);
  }
  quicksort(a, 0, n-1);
  for(i=0;i<n;i++) {
    printf("%d\t", a[i]);
  }
}