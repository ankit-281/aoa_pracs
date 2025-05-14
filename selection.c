#include <stdio.h>
void main() {
  int n, a[10], i, j, imin, temp;
  printf("Enter no. of elements of array: ");
  scanf("%d", &n);
  printf("Enter elements of array:\n");
  for(i=0;i<n;i++) {
    scanf("%d", &a[i]);
  }
  for(i=0;i<n-1;i++) {
    imin = i;
    for(j=i+1;j<n;j++) {
      if(a[j]<a[imin]) 
        imin = j;
    }
    temp = a[imin];
    a[imin] = a[i];
    a[i]= temp;
  }
  for(i=0;i<n;i++) {
    printf("%d\t", a[i]);
  }
}