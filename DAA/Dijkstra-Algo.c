#include <stdio.h>

#define MAX 10
#define INF 999

/*
==========================================================
            Dijkstra's Algorithm
==========================================================

Approach Used:
- Greedy Algorithm
- Single Source Shortest Path (SSSP)

Idea:
- Find the shortest distance from a source vertex
  to all other vertices.
- Repeatedly select the unvisited vertex having the
  minimum distance.
- Update (relax) the distances of its adjacent vertices.
- Continue until all vertices are visited.

Note:
- Works only for graphs having NON-NEGATIVE edge weights.
- Does NOT work correctly for negative edge weights.

Applications:
- GPS Navigation
- Network Routing
- Flight Route Planning
- Robot Path Planning
- Computer Networks
- Maps and Navigation Systems

==========================================================
*/

int main()
{
    int n, i, j, source;

    // Stores the minimum distance among unvisited vertices
    int min;

    // Stores the selected minimum distance vertex
    int u;

    // Cost (Adjacency) Matrix
    int cost[MAX][MAX];

    // Stores shortest distance from source
    int distance[MAX];

    // Keeps track of visited vertices
    int visited[MAX] = {0};

    //------------------------------------------------------
    // Input Number of Vertices
    //------------------------------------------------------
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    //------------------------------------------------------
    // Input Cost Matrix
    //------------------------------------------------------
    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF (except diagonal)
            // to indicate no direct edge
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    //------------------------------------------------------
    // Input Source Vertex
    //------------------------------------------------------
    printf("Enter source vertex: ");
    scanf("%d", &source);

    //------------------------------------------------------
    // Initialize Distance Array
    //------------------------------------------------------
    for(i = 0; i < n; i++)
        distance[i] = cost[source][i];

    // Source vertex is visited first
    visited[source] = 1;

    // Distance from source to itself is 0
    distance[source] = 0;

    //------------------------------------------------------
    // Dijkstra's Algorithm
    //------------------------------------------------------
    for(i = 1; i < n; i++)
    {
        min = INF;

        //--------------------------------------------------
        // Find the nearest unvisited vertex
        //--------------------------------------------------
        for(j = 0; j < n; j++)
        {
            if(!visited[j] && distance[j] < min)
            {
                min = distance[j];
                u = j;
            }
        }

        // Mark selected vertex as visited
        visited[u] = 1;

        //--------------------------------------------------
        // Relax adjacent vertices
        //--------------------------------------------------
        for(j = 0; j < n; j++)
        {
            if(!visited[j] &&
               distance[u] + cost[u][j] < distance[j])
            {
                distance[j] = distance[u] + cost[u][j];
            }
        }
    }

    //------------------------------------------------------
    // Print Shortest Distances
    //------------------------------------------------------
    printf("\nShortest Distances from Vertex %d:\n", source);

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
Time Complexity : O(V²)

Reason:
- Two nested loops are used.
- In every iteration, the algorithm searches for the
  minimum unvisited vertex and updates all vertices.

Using a Min Heap (Priority Queue):
Time Complexity = O((V + E) log V)

----------------------------------------------------------

Space Complexity : O(V²)

Reason:
- Cost Matrix = O(V²)
- Distance Array = O(V)
- Visited Array = O(V)

Overall:
O(V²)

----------------------------------------------------------

Technique Used:
✔ Greedy Algorithm
✔ Shortest Path Algorithm
✔ Edge Relaxation

----------------------------------------------------------

Where is it Used?

✔ GPS Navigation
✔ Google Maps
✔ Computer Network Routing
✔ Flight Route Planning
✔ Robot Path Planning
✔ Transportation Systems
✔ Telecommunications
✔ Logistics and Delivery Systems

----------------------------------------------------------

Input

Enter number of vertices:
4

Enter cost matrix:

0 2 4 0
2 0 1 7
4 1 0 3
0 7 3 0

Enter source vertex:
0

==========================================================
*/