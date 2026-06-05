#include <stdio.h>

int graph[10][10], color[10];
int n, m;

// Check whether color c can be assigned to vertex k
int safe(int k, int c) {
    int i;

    for(i = 0; i < n; i++) {
        if(graph[k][i] == 1 && color[i] == c)
            return 0;
    }

    return 1;
}

// Graph Coloring using Backtracking
void graphColoring(int k) {
    int c;

    if(k == n) {
        printf("Solution: ");
        for(int i = 0; i < n; i++)
            printf("%d ", color[i]);
        printf("\n");
        return;
    }

    for(c = 1; c <= m; c++) {
        if(safe(k, c)) {
            color[k] = c;
            graphColoring(k + 1);
            color[k] = 0;   // Backtrack
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(0);

    return 0;
}
