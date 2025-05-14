#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#define V 10

int minvertex(int dist[], bool dijkset[])  {
  int min = INT_MAX, mini = -1;
  for(int i=0;i<V;i++) {
    if(!dijkset[i] && dist[i]<min) {
      min = dist[i];
      mini = i;
    }
  }
  dijkset[mini] = true;
  return mini;
}

void printdijkstra(int dist[], int par[], int src) {
  printf("Dijkstra with source %d\n", src);
  printf("Vertex\tDistance\tPath\n");
  for(int i=0;i<V;i++) {
    printf("\n%d\t%d\t",i, dist[i]);
    int path[V];
    int j=i, k=0;
    while(j!=src) {
      path[k++]=par[j];
      j=par[j];
    }
    for (int p = k - 1; p >= 0; p--) {
      printf("%d->", path[p]);
    }
    printf("%d",i);
  }
}

void dijkstras(int graph[V][V], int src) {
  int dist[V];
  bool dijkset[V];
  int par[V];

  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
    dijkset[i] = false;
    par[i] = -1;
  }

  dist[src] = 0;

  for(int count=0;count<V-1;count++) {
    int u = minvertex(dist, dijkset);
    for(int v=0;v<V;v++) {
      if(!dijkset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[v]>dist[u]+graph[u][v]) {
        par[v] = u;
        dist[v] = dist[u]+graph[u][v];
      }
    }
  }

  printdijkstra(dist, par, src);
}

void main() { 
  clock_t start, end;
  start = clock();

  int graph[V][V] = {
      {0, 2, 0, 6, 0, 0, 0, 0, 0, 3},
      {2, 0, 3, 8, 5, 0, 0, 0, 0, 0},
      {0, 3, 0, 0, 7, 4, 0, 0, 0, 0},
      {6, 8, 0, 0, 9, 0, 5, 0, 0, 0},
      {0, 5, 7, 9, 0, 0, 0, 6, 0, 0},
      {0, 0, 4, 0, 0, 0, 2, 8, 0, 0},
      {0, 0, 0, 5, 0, 2, 0, 1, 6, 0},
      {0, 0, 0, 0, 6, 8, 1, 0, 4, 0},
      {0, 0, 0, 0, 0, 0, 6, 4, 0, 7},
      {3, 0, 0, 0, 0, 0, 0, 0, 7, 0}
  };

  int src = 0;
  printf("Dijkstra's Algorithm (Source: %d)\n", src);
  dijkstras(graph, src);

  end = clock();
  printf("\nTime in seconds: %f\n", (float)(end - start) / CLOCKS_PER_SEC);
}