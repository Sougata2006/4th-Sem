#include <stdio.h>
#define MAX 20
#define INF 999

struct Edge {
    int u, v, w;
};

int main() {
    int n, e, i, j, source;
    struct Edge edge[MAX];
    int distance[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter edges (source destination weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances
    for (i = 0; i < n; i++)
        distance[i] = INF;

    distance[source] = 0;

    // Relax edges n-1 times
    for (i = 1; i <= n - 1; i++) {
        for (j = 0; j < e; j++) {
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (j = 0; j < e; j++) {
        int u = edge[j].u;
        int v = edge[j].v;
        int w = edge[j].w;

        if (distance[u] != INF && distance[u] + w < distance[v]) {
            printf("Negative weight cycle detected!\n");
            return 0;
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", source, i, distance[i]);
    }

    return 0;
