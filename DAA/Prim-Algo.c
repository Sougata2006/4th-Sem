#include <stdio.h>

#define MAX 100
#define INF 999999

/*
==========================================================
            Prim's Minimum Spanning Tree (MST)
==========================================================

Approach Used:
- Greedy Algorithm
- Minimum Spanning Tree (MST)

Idea:
- Start from any vertex (here vertex 0).
- Select the minimum weight edge that connects a
  visited vertex to an unvisited vertex.
- Add the selected vertex to the MST.
- Repeat until all vertices are included.

Note:
- Works only for Connected and Undirected Graphs.
- If the graph is disconnected, an MST cannot be formed.

Applications:
- Road Construction
- Railway Networks
- Electrical Power Distribution
- Computer Networks
- Cable TV Networks
- Water Pipeline Systems

==========================================================
*/

int main()
{
    int n;

    // Cost (Adjacency) Matrix
    int cost[MAX][MAX];

    // Keeps track of visited vertices
    int visited[MAX] = {0};

    // Stores total minimum cost
    int min_cost = 0;

    // Counts number of edges selected
    int edges = 0;

    //------------------------------------------------------
    // Input Number of Vertices
    //------------------------------------------------------
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    //------------------------------------------------------
    // Input Adjacency Matrix
    //------------------------------------------------------
    printf("Enter the adjacency matrix (Enter 0 if no edge):\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF
            // indicating no direct edge
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    //------------------------------------------------------
    // Start from Vertex 0
    //------------------------------------------------------
    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    //------------------------------------------------------
    // Continue until (V-1) edges are selected
    //------------------------------------------------------
    while(edges < n - 1)
    {
        int min = INF;

        // Stores selected edge
        int u = -1;
        int v = -1;

        //--------------------------------------------------
        // Find the minimum edge connecting
        // visited and unvisited vertices
        //--------------------------------------------------
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] &&
                       cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        //--------------------------------------------------
        // Include the selected edge in MST
        //--------------------------------------------------
        if(u != -1 && v != -1)
        {
            printf("%d - %d : %d\n",
                   u,
                   v,
                   min);

            min_cost += min;

            // Mark new vertex as visited
            visited[v] = 1;

            edges++;
        }
    }

    //------------------------------------------------------
    // Display Total Minimum Cost
    //------------------------------------------------------
    printf("\nTotal Minimum Cost = %d\n",
           min_cost);

    return 0;
}

/*
==========================================================
Time Complexity : O(V²)

Reason:
- Two nested loops are used to find the minimum edge
  during every iteration.

Overall:
O(V²)

(Using Priority Queue + Adjacency List,
Time Complexity becomes O(E log V).)

----------------------------------------------------------

Space Complexity : O(V²)

Reason:
- Cost Matrix = O(V²)
- Visited Array = O(V)

Overall:
O(V²)

----------------------------------------------------------

Technique Used:
✔ Greedy Algorithm
✔ Minimum Spanning Tree (MST)

----------------------------------------------------------

Where is it Used?

✔ Road Construction
✔ Railway Network Design
✔ Electrical Grid Planning
✔ Computer Network Design
✔ Cable TV Networks
✔ Water Pipeline Systems
✔ Telecommunication Networks
✔ Minimum Cost Network Design

----------------------------------------------------------

Input

Enter number of vertices:
5

Enter the adjacency matrix (Enter 0 if no edge):

0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

==========================================================
*/