#include <stdio.h>

#define N 4      // Size of the puzzle (4x4)

/*
==========================================================
                15 Puzzle Game
==========================================================

Approach Used:
- Simulation
- Matrix Manipulation

Idea:
- Represent the puzzle as a 4x4 matrix.
- '0' represents the blank space.
- Find the blank position.
- Move the blank according to user input.
- Continue until the puzzle reaches the goal state.

Applications:
- Artificial Intelligence (AI)
- State Space Search
- Heuristic Search (A*)
- BFS & DFS Search Problems
- Game Development
- Puzzle Solvers

==========================================================
*/

// Initial Puzzle Configuration
// 0 represents the blank tile
int puzzle[N][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9,10,11,12},
    {13,14, 0,15}
};

//----------------------------------------------------------
// Function : display()
// Purpose  : Displays the current state of the puzzle.
//----------------------------------------------------------
void display()
{
    int i, j;

    printf("\n");

    // Print each row of the puzzle
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            // Print blank space instead of 0
            if(puzzle[i][j] == 0)
                printf("   ");
            else
                printf("%2d ", puzzle[i][j]);
        }

        printf("\n");
    }
}

//----------------------------------------------------------
// Function : findBlank()
// Purpose  : Finds the current position of the blank tile.
//
// Parameters:
// row -> Stores blank row index
// col -> Stores blank column index
//----------------------------------------------------------
void findBlank(int *row, int *col)
{
    int i, j;

    // Search entire puzzle
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(puzzle[i][j] == 0)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

//----------------------------------------------------------
// Function : move()
// Purpose  : Moves the blank tile according to user input.
//
// U -> Up
// D -> Down
// L -> Left
// R -> Right
//----------------------------------------------------------
void move(char direction)
{
    int r, c;

    // Find current blank position
    findBlank(&r, &c);

    switch(direction)
    {

        // Move Blank Up
        case 'U':

            if(r > 0)
            {
                // Swap blank with upper tile
                puzzle[r][c] = puzzle[r-1][c];
                puzzle[r-1][c] = 0;
            }
            break;

        // Move Blank Down
        case 'D':

            if(r < N-1)
            {
                // Swap blank with lower tile
                puzzle[r][c] = puzzle[r+1][c];
                puzzle[r+1][c] = 0;
            }
            break;

        // Move Blank Left
        case 'L':

            if(c > 0)
            {
                // Swap blank with left tile
                puzzle[r][c] = puzzle[r][c-1];
                puzzle[r][c-1] = 0;
            }
            break;

        // Move Blank Right
        case 'R':

            if(c < N-1)
            {
                // Swap blank with right tile
                puzzle[r][c] = puzzle[r][c+1];
                puzzle[r][c+1] = 0;
            }
            break;

        // Invalid Input
        default:
            printf("\nInvalid Move!\n");
    }
}

//----------------------------------------------------------
// Function : isSolved()
// Purpose  : Checks whether the puzzle has reached
//            the goal state.
//
// Returns:
// 1 -> Puzzle Solved
// 0 -> Puzzle Not Solved
//----------------------------------------------------------
int isSolved()
{
    // Goal Configuration
    int goal[N][N] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,0}
    };

    int i, j;

    // Compare current puzzle with goal state
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(puzzle[i][j] != goal[i][j])
                return 0;
        }
    }

    return 1;
}

//----------------------------------------------------------
// Main Function
//----------------------------------------------------------
int main()
{
    char moveDir;

    printf("========== 15 Puzzle Game ==========\n");

    // Continue until puzzle is solved
    while(1)
    {
        // Display current puzzle
        display();

        // Check whether puzzle is solved
        if(isSolved())
        {
            printf("\nCongratulations! Puzzle Solved.\n");
            break;
        }

        // Take user input
        printf("\nEnter Move (U/D/L/R): ");
        scanf(" %c", &moveDir);

        // Perform the move
        move(moveDir);
    }

    return 0;
}

/*
==========================================================
Time Complexity : O(N²)

Reason:
- display()     -> O(N²)
- findBlank()   -> O(N²)
- isSolved()    -> O(N²)
- move()        -> O(N²) (because it calls findBlank())

For a 4x4 puzzle,
N = 4

Overall per move:
O(N²)

----------------------------------------------------------

Space Complexity : O(N²)

Reason:
- Puzzle Matrix -> O(N²)
- Goal Matrix   -> O(N²)

Auxiliary Space:
O(1)

----------------------------------------------------------

Technique Used:
✔ Simulation
✔ Matrix Manipulation

(Advanced automatic solvers use:
✔ BFS
✔ DFS
✔ A* Search
✔ Best First Search
✔ IDA*)

----------------------------------------------------------

Where is this used?

✔ Artificial Intelligence
✔ State Space Search Problems
✔ Heuristic Search Algorithms
✔ Puzzle Solving Systems
✔ Robotics Planning
✔ Game Development
✔ Path Finding Problems

==========================================================
*/