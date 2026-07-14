#include <stdio.h>

#define MAX 20
#define INF 999

/*
==========================================================
            Bellman-Ford Algorithm
==========================================================

Approach Used:
- Graph Algorithm
- Dynamic Programming (Edge Relaxation)

Idea:
- Finds the shortest path from a single source vertex
  to all other vertices.
- Works even if the graph contains negative edge weights.
- Can also detect negative weight cycles.

Applications:
- Network Routing
- GPS Navigation
- Transportation Networks
- Currency Exchange Systems
- Detecting Negative Weight Cycles

==========================================================
*/

// Structure to store an edge
struct Edge {
    int u, v, w;   // Source, Destination and Weight
};

int main()
{
    int n, e, i, j, source;

    // Array to store all edges
    struct Edge edge[MAX];

    // Distance array
    int distance[MAX];

    //------------------------------------------------------
    // Input number of vertices and edges
    //------------------------------------------------------
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    //------------------------------------------------------
    // Input all edges
    //------------------------------------------------------
    printf("Enter edges (source destination weight):\n");

    for(i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &edge[i].u,
              &edge[i].v,
              &edge[i].w);
    }

    //------------------------------------------------------
    // Input Source Vertex
    //------------------------------------------------------
    printf("Enter source vertex: ");
    scanf("%d", &source);

    //------------------------------------------------------
    // Initialize all distances as Infinity
    //------------------------------------------------------
    for(i = 0; i < n; i++)
        distance[i] = INF;

    // Distance from source to itself is 0
    distance[source] = 0;

    //------------------------------------------------------
    // Relax all edges (V-1) times
    //------------------------------------------------------
    for(i = 1; i <= n - 1; i++)
    {
        for(j = 0; j < e; j++)
        {
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;

            // Relaxation Condition
            if(distance[u] != INF &&
               distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    //------------------------------------------------------
    // Check for Negative Weight Cycle
    //------------------------------------------------------
    for(j = 0; j < e; j++)
    {
        int u = edge[j].u;
        int v = edge[j].v;
        int w = edge[j].w;

        // If distance can still be reduced,
        // graph contains a negative cycle.
        if(distance[u] != INF &&
           distance[u] + w < distance[v])
        {
            printf("\nNegative Weight Cycle Detected!\n");
            return 0;
        }
    }

    //------------------------------------------------------
    // Print Shortest Distances
    //------------------------------------------------------
    printf("\nShortest Distances from Vertex %d\n", source);

    for(i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n",
               source,
               i,
               distance[i]);
    }

    return 0;
}

/*
==========================================================
Time Complexity : O(V × E)

Reason:
- Outer loop runs (V-1) times.
- Inner loop traverses all E edges.

Overall:
O(V × E)

----------------------------------------------------------

Space Complexity : O(V + E)

Reason:
- Distance Array = O(V)
- Edge Array = O(E)

----------------------------------------------------------

Technique Used:
✔ Dynamic Programming
✔ Edge Relaxation
✔ Single Source Shortest Path Algorithm

----------------------------------------------------------

Where is it Used?

✔ Network Routing
✔ GPS Navigation
✔ Transportation Networks
✔ Computer Networks
✔ Currency Exchange Problems
✔ Detecting Negative Weight Cycles
✔ Graph Theory Problems

----------------------------------------------------------

Input

4 5
0 1 4
0 2 5
1 2 -2
2 3 3
1 3 4
0

==========================================================
*/