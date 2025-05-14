#include <stdio.h>
void merge(int a[], int left, int mid, int right) {
  int i, j, k, n1 = mid-left+1, n2 = right-mid;
  int L[n1], R[n2];
  for(i=0;i<n1;i++) {
    L[i] = a[left+i];
  }
  for(i=0;i<n2;i++) {
    R[i] = a[mid+1+i];
  }

  i=0, j=0, k=left;

  while(i<n1 && j<n2) {
    if(L[i]<R[j])
      a[k++]=L[i++];
    else
      a[k++]=R[j++];
  }
  while (i < n1)
    a[k++] = L[i++];
  while (j < n2)
    a[k++] = R[j++];
}

void mergesort(int a[], int left, int right) {
  if(left<right) {
    int mid = (left+right)/2;
    mergesort(a, left, mid);
    mergesort(a, mid+1, right);
    merge(a, left, mid, right);
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
  mergesort(a, 0, n-1);
  for(i=0;i<n;i++) {
    printf("%d\t", a[i]);
  }
}