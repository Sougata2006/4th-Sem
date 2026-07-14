#include <stdio.h>

#define INF 9999

/*
==========================================================
            Floyd-Warshall Algorithm
==========================================================

Approach Used:
- Dynamic Programming
- All-Pairs Shortest Path (APSP)

Idea:
- Finds the shortest distance between EVERY pair of
  vertices in a weighted graph.
- Considers every vertex one by one as an intermediate
  vertex.
- Updates the shortest distance if a shorter path is
  found through the intermediate vertex.

Note:
- Works for graphs with positive and negative edge weights.
- Does NOT work correctly if the graph contains a
  Negative Weight Cycle.

Applications:
- Network Routing
- GPS Navigation
- Airline Route Planning
- Computer Networks
- Social Network Analysis
- Graph Theory Problems

==========================================================
*/

int main()
{
    int n;
    int i, j, k;

    //------------------------------------------------------
    // Input Number of Vertices
    //------------------------------------------------------
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Distance Matrix
    int dist[n][n];

    //------------------------------------------------------
    // Input Adjacency Matrix
    //------------------------------------------------------
    printf("Enter adjacency matrix:\n");
    printf("(Use %d for INF)\n", INF);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }

    //------------------------------------------------------
    // Floyd-Warshall Algorithm
    //------------------------------------------------------

    // Select every vertex as an intermediate vertex
    for(k = 0; k < n; k++)
    {
        // Select source vertex
        for(i = 0; i < n; i++)
        {
            // Select destination vertex
            for(j = 0; j < n; j++)
            {
                // If a shorter path exists through
                // intermediate vertex k, update it
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    //------------------------------------------------------
    // Display Shortest Distance Matrix
    //------------------------------------------------------
    printf("\nShortest Distance Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%4d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
==========================================================
Time Complexity : O(V³)

Reason:
- Three nested loops are used.
- Each loop runs V times.

Overall:
O(V × V × V) = O(V³)

----------------------------------------------------------

Space Complexity : O(V²)

Reason:
- Distance Matrix = O(V²)

No additional significant memory is used.

----------------------------------------------------------

Technique Used:
✔ Dynamic Programming
✔ All-Pairs Shortest Path (APSP)

----------------------------------------------------------

Where is it Used?

✔ Computer Network Routing
✔ GPS Navigation Systems
✔ Airline Route Planning
✔ Railway Route Optimization
✔ Social Network Analysis
✔ Graph Theory Problems
✔ Traffic Management Systems
✔ Distance Matrix Computation

----------------------------------------------------------

Input

Enter number of vertices:
4

Enter adjacency matrix:
(Use 9999 for INF)

0    5    9999 10
9999 0    3    9999
9999 9999 0    1
9999 9999 9999 0

==========================================================
*/