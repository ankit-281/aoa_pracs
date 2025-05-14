#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#define V 10

int minkey(int key[], bool mstSet[]) {
    int min = INT_MAX, minvertex = -1;
    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            minvertex = i;
        }
    }
    return minvertex;
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        mstSet[i] = false;
    }

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minkey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, key[i]);
    }
}

int main() {
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

    primMST(graph);

    end = clock();
    printf("\nTime in seconds: %f\n", (float)(end - start) / CLOCKS_PER_SEC);

    return 0;
}