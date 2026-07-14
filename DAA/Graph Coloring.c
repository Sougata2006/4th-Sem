#include <stdio.h>

/*
==========================================================
            Graph Coloring Problem
==========================================================

Approach Used:
- Backtracking
- Recursion

Idea:
- Assign colors to vertices one by one.
- Before assigning a color, check whether any adjacent
  vertex already has the same color.
- If the color is safe, assign it and recursively color
  the next vertex.
- If no valid color is available, backtrack and try a
  different color.

Note:
- Adjacent vertices must have different colors.
- The algorithm prints all possible valid colorings
  using the given number of colors.

Applications:
- Timetable Scheduling
- Register Allocation in Compilers
- Frequency Assignment
- Map Coloring
- Sudoku Solving
- Constraint Satisfaction Problems (CSP)

==========================================================
*/

//----------------------------------------------------------
// Global Variables
//----------------------------------------------------------

// Adjacency Matrix of Graph
int graph[10][10];

// Stores assigned color of each vertex
int color[10];

// Number of vertices
int n;

// Number of available colors
int m;

//----------------------------------------------------------
// Function : safe()
// Purpose  : Checks whether color 'c' can be assigned
//            to vertex 'k'.
//
// Returns:
// 1 -> Safe
// 0 -> Not Safe
//----------------------------------------------------------
int safe(int k, int c)
{
    int i;

    // Check all adjacent vertices
    for(i = 0; i < n; i++)
    {
        // If adjacent vertex has the same color
        if(graph[k][i] == 1 && color[i] == c)
            return 0;
    }

    return 1;
}

//----------------------------------------------------------
// Function : graphColoring()
// Purpose  : Solves Graph Coloring Problem using
//            Backtracking.
//----------------------------------------------------------
void graphColoring(int k)
{
    int c;

    //------------------------------------------------------
    // Base Case
    // All vertices are colored
    //------------------------------------------------------
    if(k == n)
    {
        printf("Solution: ");

        // Print assigned colors
        for(int i = 0; i < n; i++)
            printf("%d ", color[i]);

        printf("\n");
        return;
    }

    //------------------------------------------------------
    // Try every available color
    //------------------------------------------------------
    for(c = 1; c <= m; c++)
    {
        // Check whether current color is safe
        if(safe(k, c))
        {
            // Assign color
            color[k] = c;

            // Color next vertex
            graphColoring(k + 1);

            // Backtrack
            // Remove assigned color and try another one
            color[k] = 0;
        }
    }
}

//----------------------------------------------------------
// Main Function
//----------------------------------------------------------
int main()
{
    int i, j;

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
            scanf("%d", &graph[i][j]);
        }
    }

    //------------------------------------------------------
    // Input Number of Colors
    //------------------------------------------------------
    printf("Enter number of colors: ");
    scanf("%d", &m);

    //------------------------------------------------------
    // Start Graph Coloring from Vertex 0
    //------------------------------------------------------
    graphColoring(0);

    return 0;
}

/*
==========================================================
Time Complexity : O(M^N)

Reason:
- Each of the N vertices can be assigned one of M colors.
- In the worst case, all possible color combinations
  are explored.

Overall:
O(M^N)

----------------------------------------------------------

Space Complexity : O(N)

Reason:
- Color Array = O(N)
- Recursive Call Stack = O(N)

Overall:
O(N)

----------------------------------------------------------

Technique Used:
✔ Backtracking
✔ Recursion
✔ Constraint Satisfaction Problem (CSP)

----------------------------------------------------------

Where is it Used?

✔ Timetable Scheduling
✔ Register Allocation in Compilers
✔ Frequency Assignment
✔ Map Coloring
✔ Sudoku Solver
✔ Exam Scheduling
✔ Wireless Network Channel Assignment
✔ Constraint Satisfaction Problems (CSP)

----------------------------------------------------------

Input

Enter number of vertices:
4

Enter adjacency matrix:

0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0

Enter number of colors:
3

==========================================================
*/