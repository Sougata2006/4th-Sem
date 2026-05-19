#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Union-Find (Disjoint Set)
int parent[MAX];

// Find with path compression
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union of two sets
void unionSet(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    parent[root_u] = root_v;
}

// Comparator for sorting edges
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

int main() {
    int n, cost[MAX][MAX];
    struct Edge edges[MAX * MAX];
    int edgeCount = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Store edges (avoid duplicates, take only i < j)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != 0) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = cost[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges by weight
    qsort(edges, edgeCount, sizeof(struct Edge), compare);

    int min_cost = 0;
    int edges_used = 0;

    printf("\nEdges in MST:\n");

    for (int i = 0; i < edgeCount && edges_used < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            min_cost += edges[i].weight;
            unionSet(u, v);
            edges_used++;
        }
    }

    printf("\nTotal Minimum Cost = %d\n", min_cost);

    return 0;
}
