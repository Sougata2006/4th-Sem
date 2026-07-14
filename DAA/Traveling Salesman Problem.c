#include <stdio.h>

#define INF 9999

/*
==========================================================
        Travelling Salesman Problem (TSP)
==========================================================

Approach Used:
- Backtracking
- Recursion
- Brute Force Search

Idea:
- Start from the first city (City 0).
- Visit every unvisited city exactly once.
- After visiting all cities, return to the starting city.
- Calculate the total tour cost for every possible path.
- Keep track of the minimum tour cost.

Note:
- Every city must be visited exactly once.
- The salesman must return to the starting city.
- This Backtracking solution guarantees the optimal answer
  but becomes slow for large numbers of cities.

Applications:
- Delivery Route Optimization
- GPS Navigation
- Logistics and Supply Chain
- Robot Path Planning
- Circuit Board Manufacturing
- Vehicle Routing Problems

==========================================================
*/

//----------------------------------------------------------
// Constant representing Infinity
//----------------------------------------------------------
#define INF 9999

//----------------------------------------------------------
// Cost Matrix
// cost[i][j] = Cost to travel from city i to city j
//----------------------------------------------------------
int cost[10][10];

// Keeps track of visited cities
int visited[10];

// Number of cities
int n;

//----------------------------------------------------------
// Function : tsp()
// Purpose  : Finds the minimum travelling cost
//            using Backtracking.
//
// Parameters:
// city  -> Current City
// count -> Number of cities visited
//
// Returns:
// Minimum possible tour cost
//----------------------------------------------------------
int tsp(int city, int count)
{
    int i;

    // Initialize minimum cost as Infinity
    int minCost = INF;

    //------------------------------------------------------
    // Base Case
    // All cities have been visited
    //------------------------------------------------------
    if(count == n)
    {
        // Return to the starting city
        return cost[city][0];
    }

    //------------------------------------------------------
    // Visit every unvisited city
    //------------------------------------------------------
    for(i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            // Mark city as visited
            visited[i] = 1;

            // Calculate current tour cost
            int temp =
            cost[city][i] +
            tsp(i, count + 1);

            // Update minimum cost
            if(temp < minCost)
                minCost = temp;

            // Backtrack
            visited[i] = 0;
        }
    }

    return minCost;
}

//----------------------------------------------------------
// Main Function
//----------------------------------------------------------
int main()
{
    int i, j;

    //------------------------------------------------------
    // Input Number of Cities
    //------------------------------------------------------
    printf("Enter number of cities: ");
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
        }
    }

    //------------------------------------------------------
    // Start from City 0
    //------------------------------------------------------
    visited[0] = 1;

    //------------------------------------------------------
    // Find Minimum Tour Cost
    //------------------------------------------------------
    printf("\nMinimum Tour Cost = %d\n",
           tsp(0, 1));

    return 0;
}

/*
==========================================================
Time Complexity : O(N!)

Reason:
- The algorithm explores every possible order of
  visiting the cities.
- In the worst case, all permutations are checked.

Overall:
O(N!)

----------------------------------------------------------

Space Complexity : O(N)

Reason:
- Visited Array = O(N)
- Recursive Call Stack = O(N)

Overall:
O(N)

----------------------------------------------------------

Technique Used:
✔ Backtracking
✔ Recursion
✔ Brute Force Search

----------------------------------------------------------

Where is it Used?

✔ Delivery Route Optimization
✔ Logistics and Supply Chain
✔ GPS Navigation
✔ Robot Path Planning
✔ Airline Route Planning
✔ Vehicle Routing Problems
✔ Circuit Board Manufacturing
✔ Warehouse Optimization

----------------------------------------------------------

Input

Enter number of cities:
4

Enter cost matrix:

0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

==========================================================
*/