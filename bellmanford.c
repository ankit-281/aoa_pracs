#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#define V 10
#define E 20

typedef struct {
  int u;
  int v;
  int w;
} Edge;

void bellmanFord(Edge edge_list[], int src) {
  int dist[V], par[V];

  for(int i=0;i<V;i++) {
    dist[i] = INT_MAX;
    par[i] = -1;
  }
  dist[src] = 0;

  for(int i=0;i<V-1;i++) {
    for(int j=0;j<E;j++) {
      int u = edge_list[j].u;
      int v = edge_list[j].v;
      int w = edge_list[j].w;

      if(dist[v]>dist[u]+w && dist[u]!=INT_MAX) {
        dist[v] = dist[u]+w;
        par[v] = u;
      }
    }
  }
  for(int j=0;j<E;j++) {
    int u = edge_list[j].u;
    int v = edge_list[j].v;
    int w = edge_list[j].w;

    if(dist[v]>dist[u]+w && dist[u]!=INT_MAX) {
      printf("Negative cycle");
      return;
    }
  }

  printf("Vertex\tDistance from Source %d\tPath\n", src);
  for (int i = 0; i < V; i++) {
    if (dist[i] == INT_MAX) {
      printf("%d\tINF\t\t\tNo path\n", i);
    }
    else {
      int path[V], k=0, p=i;
      printf("%d\t%d\t\t\t", i, dist[i]);
      while(p!=src) {
        path[k++] = p;
        p = par[p];
      }
      printf("%d",src);
      for(int j = k-1;j>=0;j--) {
        printf("->%d",path[j]);
      }
      printf("\n");
    }
  }
}

void main() {
  clock_t start, end;
  start = clock();

  Edge edge_list[E] = {
    {0, 1, 2}, {0, 3, 6}, {0, 9, 3},
    {1, 2, 3}, {1, 4, 5},
    {2, 4, 7}, {2, 5, 4},
    {3, 4, 9}, {3, 6, 5},
    {4, 7, 6},
    {5, 6, 2}, {5, 7, 8},
    {6, 7, 1}, {6, 8, 6},
    {7, 8, 4}, {8, 9, 7},
    {1, 0, 2}, {2, 1, 3}, {4, 1, 5}, {9, 0, 3}
  };

  int src = 0;
  printf("Bellman-Ford Algorithm from Source %d:\n\n", src);
  bellmanFord(edge_list, src);

  end = clock();
  printf("\nTime in seconds: %f\n", (float)(end - start) / CLOCKS_PER_SEC);
}