#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
==========================================================
        Kruskal's Minimum Spanning Tree (MST)
==========================================================

Approach Used:
- Greedy Algorithm
- Disjoint Set (Union-Find)

Idea:
- Store all graph edges.
- Sort the edges in increasing order of weight.
- Select the smallest edge that does not form a cycle.
- Repeat until (V-1) edges are selected.
- The resulting graph is the Minimum Spanning Tree (MST).

Note:
- Works only for Connected and Undirected Graphs.
- If the graph is disconnected, it produces a Minimum
  Spanning Forest instead of an MST.

Applications:
- Network Design
- Road Construction
- Cable/Wire Connections
- Water Pipeline Networks
- Computer Networks
- Power Distribution Systems

==========================================================
*/

//----------------------------------------------------------
// Structure to represent an edge
//----------------------------------------------------------
struct Edge
{
    int u;          // Source Vertex
    int v;          // Destination Vertex
    int weight;     // Edge Weight
};

//----------------------------------------------------------
// Parent Array for Union-Find
//----------------------------------------------------------
int parent[MAX];

//----------------------------------------------------------
// Function : find()
// Purpose  : Finds the parent (representative) of a set.
//
// Uses Path Compression for optimization.
//----------------------------------------------------------
int find(int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

//----------------------------------------------------------
// Function : unionSet()
// Purpose  : Combines two different sets.
//----------------------------------------------------------
void unionSet(int u, int v)
{
    int root_u = find(u);
    int root_v = find(v);

    parent[root_u] = root_v;
}

//----------------------------------------------------------
// Function : compare()
// Purpose  : Comparator function used by qsort()
//            to sort edges by increasing weight.
//----------------------------------------------------------
int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight -
           ((struct Edge *)b)->weight;
}

//----------------------------------------------------------
// Main Function
//----------------------------------------------------------
int main()
{
    int n;

    // Cost (Adjacency) Matrix
    int cost[MAX][MAX];

    // Array to store all graph edges
    struct Edge edges[MAX * MAX];

    // Number of edges stored
    int edgeCount = 0;

    //------------------------------------------------------
    // Input Number of Vertices
    //------------------------------------------------------
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    //------------------------------------------------------
    // Input Adjacency Matrix
    //------------------------------------------------------
    printf("Enter adjacency matrix (0 if no edge):\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    //------------------------------------------------------
    // Initialize Parent Array
    //------------------------------------------------------
    for(int i = 0; i < n; i++)
        parent[i] = i;

    //------------------------------------------------------
    // Store all edges
    // (Take only i < j to avoid duplicate edges)
    //------------------------------------------------------
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(cost[i][j] != 0)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = cost[i][j];

                edgeCount++;
            }
        }
    }

    //------------------------------------------------------
    // Sort edges according to weight
    //------------------------------------------------------
    qsort(edges,
          edgeCount,
          sizeof(struct Edge),
          compare);

    int min_cost = 0;

    // Number of edges included in MST
    int edges_used = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    //------------------------------------------------------
    // Kruskal's Algorithm
    //------------------------------------------------------
    for(int i = 0;
        i < edgeCount && edges_used < n - 1;
        i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        // Include edge only if it doesn't form a cycle
        if(find(u) != find(v))
        {
            printf("%d - %d : %d\n",
                   u,
                   v,
                   edges[i].weight);

            min_cost += edges[i].weight;

            // Merge both sets
            unionSet(u, v);

            edges_used++;
        }
    }

    //------------------------------------------------------
    // Display Minimum Cost
    //------------------------------------------------------
    printf("\nTotal Minimum Cost = %d\n",
           min_cost);

    return 0;
}

/*
==========================================================
Time Complexity : O(E log E)

Reason:
- Sorting all edges takes O(E log E).
- Union-Find operations are nearly O(1).
- Therefore sorting dominates the complexity.

Overall:
O(E log E)

----------------------------------------------------------

Space Complexity : O(V + E)

Reason:
- Parent Array = O(V)
- Edge Array = O(E)

Overall:
O(V + E)

----------------------------------------------------------

Technique Used:
✔ Greedy Algorithm
✔ Minimum Spanning Tree (MST)
✔ Union-Find (Disjoint Set)
✔ Edge Sorting

----------------------------------------------------------

Where is it Used?

✔ Road Construction
✔ Railway Network Design
✔ Electrical Power Distribution
✔ Computer Network Design
✔ Water Pipeline Networks
✔ Cable TV Networks
✔ Telecommunication Networks
✔ Minimum Cost Network Design

----------------------------------------------------------

Input

Enter number of vertices:
4

Enter adjacency matrix (0 if no edge):

0 10 6 5
10 0 0 15
6 0 0 4
5 15 4 0

==========================================================
*/