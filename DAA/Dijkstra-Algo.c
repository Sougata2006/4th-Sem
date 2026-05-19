#include <stdio.h>
#define MAX 10
#define INF 999

int main() {
    int n, i, j, source, min, u;
    int cost[MAX][MAX], distance[MAX], visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances
    for (i = 0; i < n; i++)
        distance[i] = cost[source][i];

    visited[source] = 1;
    distance[source] = 0;

    // Dijkstra's Algorithm
    for (i = 1; i < n; i++) {
        min = INF;

        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[u] + cost[u][j] < distance[j]) {
                distance[j] = distance[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);
    for (i = 0; i < n; i++)
        printf("%d -> %d = %d\n", source, i, distance[i]);

    return 0;
}
