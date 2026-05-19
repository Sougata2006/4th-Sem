#include <stdio.h>
#define MAX 100
#define INF 999999

int main() {
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int min_cost = 0;
    int edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; // No edge treated as infinity
        }
    }

    visited[0] = 1; // Start from vertex 0

    printf("\nEdges in MST:\n");

    while (edges < n - 1) {
        int min = INF, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d - %d : %d\n", u, v, min);
            min_cost += min;
            visited[v] = 1;
            edges++;
        }
    }

    printf("\nTotal Minimum Cost = %d\n", min_cost);

    return 0;
}
