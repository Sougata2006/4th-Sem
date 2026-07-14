#include <stdio.h>
#include <stdlib.h>

/*
==========================================================
            N-Queen Problem (8-Queen)
==========================================================

Approach Used:
- Backtracking
- Recursion

Idea:
- Place one queen in each row.
- Before placing a queen, check whether the position is safe.
- If safe, place it and recursively solve the next row.
- If no safe position exists, automatically backtrack.

Applications:
- Sudoku Solver
- Rat in a Maze
- Graph Coloring
- Knight's Tour
- Hamiltonian Path
- Constraint Satisfaction Problems (CSP)

*/

int x[8];   // x[i] stores the column number of the queen placed in row i

//--------------------------------------------------------
// Function : place()
// Purpose  : Checks whether a queen can be placed safely
//            at row k and column i.
//
// Returns:
// 1 -> Safe position
// 0 -> Unsafe position
//--------------------------------------------------------
int place(int k, int i)
{
    int j;

    // Compare with all previously placed queens
    for(j = 0; j < k; j++)
    {
        // Same Column
        // OR
        // Same Diagonal
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }

    return 1;
}

//--------------------------------------------------------
// Function : queen()
// Purpose  : Places queens row by row using Backtracking.
//--------------------------------------------------------
void queen(int k)
{
    int i, j;

    // Try every column in the current row
    for(i = 0; i < 8; i++)
    {

        // Check whether current position is safe
        if(place(k, i))
        {

            // Place queen
            x[k] = i;

            // If last row is reached,
            // one complete solution is found
            if(k == 7)
            {
                printf("\nSolution:\n");

                // Print all queen positions
                for(j = 0; j < 8; j++)
                    printf("Row %d -> Column %d\n", j + 1, x[j] + 1);
            }
            else
            {
                // Solve for next row
                queen(k + 1);
            }

            /*
            No explicit backtracking statement is needed.

            Reason:
            When recursion returns,
            x[k] will automatically be replaced by
            the next column in the loop.
            */
        }
    }
}

//--------------------------------------------------------
// Driver Function
//--------------------------------------------------------
int main()
{
    // Start placing queens from Row 0
    queen(0);

    return 0;
}

/*
==========================================================
Time Complexity  : O(N!)

Reason:
- Every row tries multiple columns.
- Worst case explores approximately N! arrangements.

For this program:
N = 8
Time = O(8!)

----------------------------------------------------------

Space Complexity : O(N)

Reason:
- O(N) recursion stack
- O(N) array to store queen positions

----------------------------------------------------------

Technique Used:
✔ Backtracking
✔ Recursion

Where is this used?
✔ N Queen Problem
✔ Sudoku Solver
✔ Rat in a Maze
✔ Knight's Tour
✔ Graph Coloring
✔ Hamiltonian Cycle
✔ Permutation Generation
✔ Constraint Satisfaction Problems (CSP)

==========================================================
*/