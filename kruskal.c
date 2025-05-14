#include <stdio.h>
#include <limits.h>

typedef struct {
  int u;
  int v;
  int w;
} Edge;

int find_par(int par[], int i) {
  if(par[i]!=i)
    par[i] = find_par(par, par[i]);
  return par[i];
}

void sortEdges(Edge edge_list[], int E) {
  for(int i=0;i<E-1;i++) {
    for(int j=0;j<E-i-1;j++) {
      if(edge_list[j].w>edge_list[j+1].w) {
        Edge temp = edge_list[j];
        edge_list[j] = edge_list[j+1];
        edge_list[j+1] = temp;
      }
    }
  }
}

void kruskals(Edge edge_list[], int E, int V) {
  int par[V], total_cost = 0;
  for(int i=0;i<V;i++) {
    par[i] = i;
  }
  
  for(int i=0;i<E;i++) {
    int u = edge_list[i].u;
    int v = edge_list[i].v;
    int w = edge_list[i].w;
    
    int par_u = find_par(par, u);
    int par_v = find_par(par, v);
    if(par_u != par_v) {
      printf("%d - %d \tWeight: %d\n", u, v, w);
      total_cost += w;
      par[par_v] = par_u;
    }
  }
  printf("\nTotal Cost of MST: %d\n", total_cost);
}

void main() {
  int V, E;
  printf("Enter number of vertices: ");
  scanf("%d", &V);
  printf("Enter number of edges: ");
  scanf("%d", &E);

  Edge edge_list[E];
  for (int i = 0; i < E; i++) {
    printf("Enter u, v, weight: ");
    scanf("%d %d %d", &edge_list[i].u, &edge_list[i].v, &edge_list[i].w);
  }

  sortEdges(edge_list, E);
  kruskals(edge_list, E, V);
}