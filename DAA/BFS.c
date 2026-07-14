#include <stdio.h>

#define MAX 10

/*
==========================================================
            Breadth First Search (BFS)
==========================================================

Approach Used:
- Graph Traversal
- Breadth First Search (BFS)
- Queue

Idea:
- Start from a given source vertex.
- Visit all its adjacent (neighbor) vertices first.
- Continue level by level until every reachable vertex
  has been visited.

Applications:
- Shortest Path in an Unweighted Graph
- Social Network Analysis
- Web Crawlers
- Network Broadcasting
- GPS Navigation
- Connected Components

==========================================================
*/

int main()
{
    int n, i, j, start;

    // Adjacency Matrix Representation of Graph
    int adj[MAX][MAX];

    // Keeps track of visited vertices
    int visited[MAX] = {0};

    // Queue used for BFS traversal
    int queue[MAX];

    int front = 0;
    int rear = 0;

    //------------------------------------------------------
    // Input Number of Vertices
    //------------------------------------------------------
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    //------------------------------------------------------
    // Input Adjacency Matrix
    //------------------------------------------------------
    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    //------------------------------------------------------
    // Input Starting Vertex
    //------------------------------------------------------
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    //------------------------------------------------------
    // Initialize BFS
    //------------------------------------------------------

    // Insert starting vertex into queue
    queue[rear++] = start;

    // Mark starting vertex as visited
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    //------------------------------------------------------
    // Continue until queue becomes empty
    //------------------------------------------------------
    while(front < rear)
    {
        // Remove front vertex from queue
        int v = queue[front++];

        // Print current vertex
        printf("%d ", v);

        // Visit all adjacent vertices
        for(i = 0; i < n; i++)
        {
            // If an edge exists and the vertex is not visited
            if(adj[v][i] == 1 && visited[i] == 0)
            {
                // Add vertex to queue
                queue[rear++] = i;

                // Mark it as visited
                visited[i] = 1;
            }
        }
    }

    return 0;
}

/*
==========================================================
Time Complexity : O(V²)

Reason:
- Graph is represented using an Adjacency Matrix.
- For every vertex, all V columns are checked.

If Adjacency List is used:
Time Complexity = O(V + E)

----------------------------------------------------------

Space Complexity : O(V)

Reason:
- Visited Array = O(V)
- Queue = O(V)

Overall:
O(V)

----------------------------------------------------------

Technique Used:
✔ Breadth First Search (BFS)
✔ Queue
✔ Graph Traversal

----------------------------------------------------------

Where is it Used?

✔ Shortest Path in Unweighted Graph
✔ Social Networks (Friend Suggestions)
✔ Web Crawlers
✔ Network Broadcasting
✔ Connected Components
✔ GPS Navigation
✔ Peer-to-Peer Networks
✔ AI Search Problems

----------------------------------------------------------

Input

5

0 1 1 0 0
1 0 0 1 1
1 0 0 0 1
0 1 0 0 0
0 1 1 0 0

0

==========================================================
*/