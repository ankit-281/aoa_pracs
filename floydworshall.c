#include <stdio.h>

#define V 10
#define INF 9999

void printPath(int par[V][V], int u, int v) {
  if (u == v) {
    printf("%d ", u);
    return;
  }
  if (par[u][v] == -1) {
    printf("No path");
    return;
  }
  printPath(par, u, par[u][v]);
  printf("%d ", v);
}

void floydWarshall(int graph[V][V]) {
  int dist[V][V], par[V][V];

  // Initialize dist and par matrices
  for (int u = 0; u < V; u++) {
    for (int v = 0; v < V; v++) {
      dist[u][v] = graph[u][v];
      if (u == v || graph[u][v] == INF)
        par[u][v] = -1;
      else
        par[u][v] = u;
    }
  }

  // Floyd-Warshall algorithm
  for (int k = 0; k < V; k++) {
    for (int u = 0; u < V; u++) {
      for (int v = 0; v < V; v++) {
        if (dist[u][k] != INF && dist[k][v] != INF && dist[u][k] + dist[k][v] < dist[u][v]) {
          dist[u][v] = dist[u][k] + dist[k][v];
          par[u][v] = par[k][v];
        }
      }
    }
  }

  // Print shortest distance matrix
  printf("Shortest Distance Matrix:\n");
  for (int u = 0; u < V; u++) {
    for (int v = 0; v < V; v++) {
      if (dist[u][v] == INF)
        printf("INF\t");
      else
        printf("%d\t", dist[u][v]);
    }
    printf("\n");
  }

  // Print all shortest paths
  printf("\nShortest Paths:\n");
  for (int u = 0; u < V; u++) {
    for (int v = 0; v < V; v++) {
      if (u != v) {
        printf("Path from %d to %d: ", u, v);
        if (dist[u][v] == INF)
          printf("No path\n");
        else {
          printPath(par, u, v);
          printf("(Cost: %d)\n", dist[u][v]);
        }
      }
    }
  }
}

void main() {
  int graph[V][V] = {
    {0,   2, INF, 6, INF, INF, INF, INF, INF, 3},
    {2,   0,   3, 8,   5, INF, INF, INF, INF, INF},
    {INF, 3,   0, INF, 7,   4, INF, INF, INF, INF},
    {6,   8, INF, 0,   9, INF, 5, INF, INF, INF},
    {INF, 5,   7, 9,   0, INF, INF, 6, INF, INF},
    {INF, INF, 4, INF, INF, 0,   2, 8, INF, INF},
    {INF, INF, INF, 5, INF, 2,   0, 1, 6, INF},
    {INF, INF, INF, INF, 6, 8,   1, 0, 4, INF},
    {INF, INF, INF, INF, INF, INF, 6, 4, 0, 7},
    {3, INF, INF, INF, INF, INF, INF, INF, 7, 0}
  };

  floydWarshall(graph);
}
