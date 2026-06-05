#include <stdio.h>

#define INF 9999

int main() {
    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int dist[n][n];

    printf("Enter adjacency matrix:\n");
    printf("(Use 9999 for INF)\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Floyd-Warshall Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nShortest Distance Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%4d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
