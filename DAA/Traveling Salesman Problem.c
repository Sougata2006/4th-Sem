#include <stdio.h>

#define INF 9999

int cost[10][10], visited[10];
int n;

int tsp(int city, int count) {
    int i, minCost = INF;

    if (count == n) {
        return cost[city][0];   // Return to starting city
    }

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;

            int temp = cost[city][i] +
                       tsp(i, count + 1);

            if (temp < minCost)
                minCost = temp;

            visited[i] = 0;   // Backtrack
        }
    }

    return minCost;
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    printf("Minimum tour cost = %d\n",
           tsp(0, 1));

    return 0;
}
