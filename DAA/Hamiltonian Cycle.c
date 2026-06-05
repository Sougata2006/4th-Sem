#include <stdio.h>

#define N 5

int graph[N][N] = {
    {0,1,0,1,1},
    {1,0,1,1,0},
    {0,1,0,1,0},
    {1,1,1,0,1},
    {1,0,0,1,0}
};

int path[N];

// Check if vertex v can be added at position pos
int isSafe(int v, int pos) {

    // Must be adjacent to previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    // Vertex should not already be in path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

// Recursive function
int hamiltonian(int pos) {

    // All vertices included
    if (pos == N) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    for (int v = 1; v < N; v++) {

        if (isSafe(v, pos)) {

            path[pos] = v;

            if (hamiltonian(pos + 1))
                return 1;

            // Backtrack
            path[pos] = -1;
        }
    }

    return 0;
}

int main() {

    for (int i = 0; i < N; i++)
        path[i] = -1;

    path[0] = 0;   // Start from vertex 0

    if (hamiltonian(1)) {

        printf("Hamiltonian Cycle:\n");

        for (int i = 0; i < N; i++)
            printf("%d ", path[i]);

        printf("%d\n", path[0]); // Return to start
    }
    else {
        printf("No Hamiltonian Cycle exists.\n");
    }

    return 0;
}
