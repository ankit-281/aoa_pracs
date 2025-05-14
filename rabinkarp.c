#include <string.h>
#include <stdio.h>
#define d 256

void rabinKarp(char T[], char P[], int q) {
  int m=strlen(P), n=strlen(T), t=0, p=0, h=1;
  for(int i=0;i<m-1;i++)
    h = (h*d)%q;
  for(int i=0;i<m;i++) {
    t = (d*t+T[i])%q;
    p = (d*p+P[i])%q;
  }
  for(int s=0;s<=n-m;s++) {
    if(t==p) {
      int match = 1;
      for(int i=0;i<m;i++) {
        if(T[s+i]!=P[i]) {
          match = 0;
          break;
        }
      }
      if(match) {
        printf("Pattern occurs with shift %d\n", s);
      }
    }
    if(s<n-m) {
      t = (d*(t-T[s]*h)+T[s+m])%q;
      if(t<0)
        t+=q;
    }
  }
}


void main() {
  char T[] = "GEEKS FOR GEEKS";
  char P[] = "GEEK";
  int q = 101;
  rabinKarp(T, P, q);
}
