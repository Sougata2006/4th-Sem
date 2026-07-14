#include <stdio.h>

/*
==========================================================
        Fractional Knapsack Problem
==========================================================

Approach Used:
- Greedy Algorithm

Idea:
- Calculate Profit/Weight ratio for every item.
- Sort all items in decreasing order of ratio.
- Pick items having the highest ratio first.
- If the whole item cannot fit into the knapsack,
  take only the required fraction.

Note:
- Fractional Knapsack allows breaking an item into parts.
- This Greedy approach gives the Optimal Solution.
- This approach DOES NOT work for 0/1 Knapsack.

Applications:
- Cargo Loading
- Resource Allocation
- Investment Planning
- Budget Optimization
- Storage Management
- Logistics

==========================================================
*/

// Structure to store an item's information
struct Item
{
    int weight;
    int profit;
    float ratio;      // Profit / Weight
};

int main()
{
    int n, i, j;

    float capacity;
    float totalProfit = 0.0;

    //------------------------------------------------------
    // Input Number of Items
    //------------------------------------------------------
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Array to store all items
    struct Item item[n];

    //------------------------------------------------------
    // Input Profit and Weight of each item
    //------------------------------------------------------
    printf("Enter profit and weight of each item:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d %d",
              &item[i].profit,
              &item[i].weight);

        // Calculate Profit / Weight Ratio
        item[i].ratio =
        (float)item[i].profit / item[i].weight;
    }

    //------------------------------------------------------
    // Input Knapsack Capacity
    //------------------------------------------------------
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    //------------------------------------------------------
    // Sort items according to Profit/Weight Ratio
    // (Descending Order)
    //------------------------------------------------------
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(item[i].ratio < item[j].ratio)
            {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    printf("\nSelected Items:\n");

    //------------------------------------------------------
    // Select Items
    //------------------------------------------------------
    for(i = 0; i < n; i++)
    {
        // If complete item fits in the knapsack
        if(item[i].weight <= capacity)
        {
            capacity -= item[i].weight;

            totalProfit += item[i].profit;

            printf("Took Full Item -> ");
            printf("Profit = %d Weight = %d\n",
                   item[i].profit,
                   item[i].weight);
        }

        // Otherwise, take only the required fraction
        else
        {
            float fraction =
            capacity / item[i].weight;

            totalProfit +=
            item[i].profit * fraction;

            printf("Took %.2f Fraction of Item -> ",
                   fraction);

            printf("Profit = %d Weight = %d\n",
                   item[i].profit,
                   item[i].weight);

            // Knapsack becomes full
            capacity = 0;

            break;
        }
    }

    //------------------------------------------------------
    // Display Maximum Profit
    //------------------------------------------------------
    printf("\nMaximum Profit = %.2f\n",
           totalProfit);

    return 0;
}

/*
==========================================================
Time Complexity : O(N²)

Reason:
- Sorting using Bubble Sort takes O(N²).
- Selecting items takes O(N).

Overall:
O(N²)

(Note:
If Merge Sort or Quick Sort is used,
Time Complexity becomes O(N log N).)

----------------------------------------------------------

Space Complexity : O(N)

Reason:
- Array of items stores N elements.

Auxiliary Space:
O(1)

Overall:
O(N)

----------------------------------------------------------

Technique Used:
✔ Greedy Algorithm
✔ Sorting
✔ Profit/Weight Ratio Method

----------------------------------------------------------

Where is it Used?

✔ Cargo Loading
✔ Resource Allocation
✔ Investment Planning
✔ Budget Optimization
✔ Storage Management
✔ Logistics
✔ Warehouse Management
✔ Capital Investment Problems

----------------------------------------------------------

Input

Enter number of items:
3

Enter profit and weight of each item:
60 10
100 20
120 30

Enter knapsack capacity:
50

==========================================================
*/