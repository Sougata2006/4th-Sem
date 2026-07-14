#include <stdio.h>

#define N 5

/*
==========================================================
            Hamiltonian Cycle Problem
==========================================================

Approach Used:
- Backtracking
- Recursion

Idea:
- Start from any vertex (here vertex 0).
- Try to visit every other vertex exactly once.
- Before adding a vertex, check:
    1. It is connected to the previous vertex.
    2. It has not already been visited.
- If all vertices are visited and the last vertex
  is connected back to the starting vertex,
  then a Hamiltonian Cycle exists.
- Otherwise, backtrack and try another path.

Note:
- A Hamiltonian Cycle visits every vertex exactly once
  and finally returns to the starting vertex.
- It is different from an Euler Cycle, which visits
  every edge exactly once.

Applications:
- Route Optimization
- Traveling Salesman Problem (TSP)
- Network Design
- Robotics Path Planning
- Circuit Design
- Game AI

==========================================================
*/

//----------------------------------------------------------
// Graph Representation using Adjacency Matrix
//----------------------------------------------------------
int graph[N][N] =
{
    {0,1,0,1,1},
    {1,0,1,1,0},
    {0,1,0,1,0},
    {1,1,1,0,1},
    {1,0,0,1,0}
};

// Stores the Hamiltonian Path
int path[N];

//----------------------------------------------------------
// Function : isSafe()
// Purpose  : Checks whether vertex 'v' can be placed
//            at position 'pos' in the path.
//
// Returns:
// 1 -> Safe
// 0 -> Not Safe
//----------------------------------------------------------
int isSafe(int v, int pos)
{
    // Vertex must be adjacent to previous vertex
    if(graph[path[pos - 1]][v] == 0)
        return 0;

    // Vertex should not already exist in the path
    for(int i = 0; i < pos; i++)
    {
        if(path[i] == v)
            return 0;
    }

    return 1;
}

//----------------------------------------------------------
// Function : hamiltonian()
// Purpose  : Finds Hamiltonian Cycle using Backtracking.
//
// Returns:
// 1 -> Cycle Found
// 0 -> Cycle Not Found
//----------------------------------------------------------
int hamiltonian(int pos)
{
    //------------------------------------------------------
    // Base Case
    // All vertices are included
    //------------------------------------------------------
    if(pos == N)
    {
        // Check if last vertex connects to first vertex
        if(graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    //------------------------------------------------------
    // Try every remaining vertex
    //------------------------------------------------------
    for(int v = 1; v < N; v++)
    {
        if(isSafe(v, pos))
        {
            // Add vertex to path
            path[pos] = v;

            // Recursively solve for next position
            if(hamiltonian(pos + 1))
                return 1;

            // Backtrack
            path[pos] = -1;
        }
    }

    return 0;
}

//----------------------------------------------------------
// Main Function
//----------------------------------------------------------
int main()
{
    // Initialize all path values to -1
    for(int i = 0; i < N; i++)
        path[i] = -1;

    // Start from vertex 0
    path[0] = 0;

    //------------------------------------------------------
    // Find Hamiltonian Cycle
    //------------------------------------------------------
    if(hamiltonian(1))
    {
        printf("Hamiltonian Cycle:\n");

        // Print the cycle
        for(int i = 0; i < N; i++)
            printf("%d ", path[i]);

        // Return to starting vertex
        printf("%d\n", path[0]);
    }
    else
    {
        printf("No Hamiltonian Cycle Exists.\n");
    }

    return 0;
}

/*
==========================================================
Time Complexity : O(N!)

Reason:
- Every vertex may try every remaining vertex.
- Worst case explores nearly all permutations
  before finding a valid cycle.

Overall:
O(N!)

----------------------------------------------------------

Space Complexity : O(N)

Reason:
- Path Array = O(N)
- Recursive Call Stack = O(N)

Overall:
O(N)

----------------------------------------------------------

Technique Used:
✔ Backtracking
✔ Recursion
✔ Graph Traversal

----------------------------------------------------------

Where is it Used?

✔ Traveling Salesman Problem (TSP)
✔ Route Optimization
✔ Robotics Path Planning
✔ Circuit Design
✔ Network Design
✔ DNA Sequencing
✔ Game AI
✔ Logistics and Delivery Optimization

----------------------------------------------------------

Input

Not Required

(The graph is already defined inside the program.)

==========================================================
*/