#include <stdio.h>
void main() {
  int n, a[10], i, j, key, temp;
  printf("Enter no. of elements of array: ");
  scanf("%d", &n);
  printf("Enter elements of array:\n");
  for(i=0;i<n;i++) {
    scanf("%d", &a[i]);
  }
  for(i=1;i<n;i++) {
    key = a[i];
    j=i-1;
    while(j>=0 && a[j]>key) {
      a[j+1] = a[j];
      j=j-1;
    }
    a[j+1] = key;
  }
  for(i=0;i<n;i++) {
    printf("%d\t", a[i]);
  }
}