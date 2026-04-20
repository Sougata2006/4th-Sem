#include <stdio.h>
#define MAX 10

int main() {
    int n, i, j, start;
    int adj[MAX][MAX], visited[MAX] = {0};
    int stack[MAX], top = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Push start vertex
    stack[++top] = start;

    printf("DFS Traversal: ");

    while (top != -1) {
        int v = stack[top--];

        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
        }

        // Push adjacent vertices (reverse order for correct sequence)
        for (i = n - 1; i >= 0; i--) {
            if (adj[v][i] == 1 && !visited[i]) {
                stack[++top] = i;
            }
        }
    }

    return 0;
}
