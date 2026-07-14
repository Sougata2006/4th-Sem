#include <stdio.h>

#define MAX 10

/*
==========================================================
            Depth First Search (DFS)
==========================================================

Approach Used:
- Graph Traversal
- Depth First Search (DFS)
- Stack (Iterative)

Idea:
- Start from the given source vertex.
- Visit the current vertex.
- Move as deep as possible into the graph before
  backtracking.
- A stack is used to keep track of the next vertex
  to visit.

Applications:
- Path Finding
- Cycle Detection
- Topological Sorting
- Connected Components
- Maze Solving
- Artificial Intelligence

==========================================================
*/

int main()
{
    int n, i, j, start;

    // Adjacency Matrix Representation of Graph
    int adj[MAX][MAX];

    // Keeps track of visited vertices
    int visited[MAX] = {0};

    // Stack used for DFS traversal
    int stack[MAX];

    int top = -1;

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
    // Push the starting vertex onto the stack
    //------------------------------------------------------
    stack[++top] = start;

    printf("\nDFS Traversal: ");

    //------------------------------------------------------
    // Continue until the stack becomes empty
    //------------------------------------------------------
    while(top != -1)
    {
        // Pop the top vertex from the stack
        int v = stack[top--];

        // Visit the vertex if it is not already visited
        if(!visited[v])
        {
            printf("%d ", v);
            visited[v] = 1;
        }

        //--------------------------------------------------
        // Push all adjacent unvisited vertices
        // in reverse order so traversal follows
        // the natural left-to-right order.
        //--------------------------------------------------
        for(i = n - 1; i >= 0; i--)
        {
            if(adj[v][i] == 1 && !visited[i])
            {
                stack[++top] = i;
            }
        }
    }

    return 0;
}

/*
==========================================================
Time Complexity : O(V²)

Reason:
- The graph is represented using an Adjacency Matrix.
- For every visited vertex, all V columns are checked.

If Adjacency List is used:
Time Complexity = O(V + E)

----------------------------------------------------------

Space Complexity : O(V)

Reason:
- Stack = O(V)
- Visited Array = O(V)

Overall:
O(V)

----------------------------------------------------------

Technique Used:
✔ Depth First Search (DFS)
✔ Stack (Iterative)
✔ Graph Traversal

----------------------------------------------------------

Where is it Used?

✔ Path Finding
✔ Cycle Detection
✔ Topological Sorting
✔ Connected Components
✔ Maze Solving
✔ Artificial Intelligence
✔ Dependency Resolution
✔ Network Analysis

----------------------------------------------------------

Input

Enter number of vertices:
5

Enter adjacency matrix:

0 1 1 0 0
1 0 0 1 1
1 0 0 0 1
0 1 0 0 0
0 1 1 0 0

Enter starting vertex:
0

==========================================================
*/