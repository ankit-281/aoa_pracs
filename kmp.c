#include <stdio.h>
#include <string.h>

#define MAX 100

void compute_prefix(char P[], int pi[]) {
  pi[0] = 0;
  int j=0;
  for(int i=1;i<strlen(P);i++) {
    while(j>0 && P[i]!=P[j])
      j = pi[j-1];
    if(P[j]==P[i])
      j++;
    pi[i]=j;
  }
}

void KMP(char T[], char P[]) {
  int pi[MAX];
  compute_prefix(P, pi);
  int q = 0;
  for(int i=0;i<strlen(T);i++) {
    while(q>0 && T[i]!=P[q])
      q = pi[q-1];
    if(T[i]==P[q])
      q++;
    if(q==strlen(P)) {
      printf("Pattern occurs at shift %d\n",i-strlen(P)+1);
      q = pi[q-1];
    }
  }
}

void main() {
  char T[] = "ababcabcabababd";
  char P[] = "ababd";
  KMP(T, P);
}