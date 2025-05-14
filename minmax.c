#include <stdio.h>

void minmax(int a[], int low, int high, int *min, int* max) {
  if(low==high) {
    if(a[low]<*min)
      *min = a[low];
    if(a[low]>*max)
      *max = a[low];
    return;
  }

  if(low+1==high) {
    if(a[low]<a[high]) {
      if(a[low]<*min)
        *min = a[low];
      if(a[high]>*max)
        *max = a[high];
    }
    else {
      if(a[high]<*min)
        *min = a[high];
      if(a[low]>*max)
        *max = a[low];
    }
    return;
  }

  int mid = (low+high)/2;
  minmax(a, low, mid, min, max);
  minmax(a, mid+1, high, min, max);
}

void main() {
  int n, a[10], i, min, max;
  printf("Enter no. of elements of array: ");
  scanf("%d", &n);
  printf("Enter elements of array:\n");
  for(i=0;i<n;i++) {
    scanf("%d", &a[i]);
  }
  min = max = a[0];
  minmax(a, 0, n-1, &min, &max);
  printf("\nMIN: %d", min);
  printf("\nMAX: %d", max);
}