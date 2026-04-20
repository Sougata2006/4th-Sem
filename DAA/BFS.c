#include <stdio.h>
#define MAX 10

int main() {
    int n, i, j, start;
    int adj[MAX][MAX], visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // BFS
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
