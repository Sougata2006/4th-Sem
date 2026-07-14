#include <stdio.h>
#include <time.h>

/*
==========================================================
    Find Minimum and Maximum using Divide & Conquer
==========================================================

Approach Used:
- Divide and Conquer
- Recursion

Idea:
- Divide the array into two halves.
- Recursively find the minimum and maximum of both halves.
- Compare the results and return the overall minimum
  and maximum.
- This approach reduces the total number of comparisons
  compared to the simple linear method.

Applications:
- Statistical Data Analysis
- Competitive Programming
- Data Processing
- Scientific Computing
- Searching Large Arrays
- Optimization Problems

==========================================================
*/

//----------------------------------------------------------
// Structure to store Minimum and Maximum values
//----------------------------------------------------------
struct Pair
{
    int min;
    int max;
};

//----------------------------------------------------------
// Function : findMinMax()
// Purpose  : Finds the minimum and maximum elements
//            using Divide and Conquer.
//
// Parameters:
// arr[] -> Input Array
// low   -> Starting Index
// high  -> Ending Index
//
// Returns:
// Structure containing Minimum and Maximum values
//----------------------------------------------------------
struct Pair findMinMax(int arr[], int low, int high)
{
    struct Pair result;
    struct Pair left;
    struct Pair right;

    //------------------------------------------------------
    // Base Case 1
    // Only one element in the array
    //------------------------------------------------------
    if(low == high)
    {
        result.min = arr[low];
        result.max = arr[low];

        return result;
    }

    //------------------------------------------------------
    // Base Case 2
    // Only two elements
    //------------------------------------------------------
    if(high == low + 1)
    {
        if(arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }

        return result;
    }

    //------------------------------------------------------
    // Divide the array into two halves
    //------------------------------------------------------
    int mid = (low + high) / 2;

    //------------------------------------------------------
    // Conquer
    // Find Min and Max in Left Half
    //------------------------------------------------------
    left = findMinMax(arr, low, mid);

    //------------------------------------------------------
    // Find Min and Max in Right Half
    //------------------------------------------------------
    right = findMinMax(arr, mid + 1, high);

    //------------------------------------------------------
    // Combine Results
    //------------------------------------------------------

    // Overall Minimum
    result.min =
    (left.min < right.min) ? left.min : right.min;

    // Overall Maximum
    result.max =
    (left.max > right.max) ? left.max : right.max;

    return result;
}

//----------------------------------------------------------
// Main Function
//----------------------------------------------------------
int main()
{
    int n, i;

    //------------------------------------------------------
    // Input Number of Elements
    //------------------------------------------------------
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    //------------------------------------------------------
    // Input Array Elements
    //------------------------------------------------------
    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    //------------------------------------------------------
    // Start Execution Time
    //------------------------------------------------------
    clock_t start = clock();

    // Find Minimum and Maximum
    struct Pair result =
    findMinMax(arr, 0, n - 1);

    //------------------------------------------------------
    // End Execution Time
    //------------------------------------------------------
    clock_t end = clock();

    // Calculate Execution Time
    double time_taken =
    ((double)(end - start)) / CLOCKS_PER_SEC;

    //------------------------------------------------------
    // Display Result
    //------------------------------------------------------
    printf("\nMinimum Element = %d\n", result.min);
    printf("Maximum Element = %d\n", result.max);

    printf("Execution Time : %f seconds\n",
           time_taken);

    return 0;
}

/*
==========================================================
Time Complexity : O(N)

Reason:
- Every element is visited exactly once while dividing
  and combining the array.
- The recursion processes all elements efficiently.

Overall:
O(N)

----------------------------------------------------------

Space Complexity : O(log N)

Reason:
- Recursive function calls create a recursion stack.
- Maximum recursion depth is log N.

----------------------------------------------------------

Technique Used:
✔ Divide and Conquer
✔ Recursion

----------------------------------------------------------

Where is it Used?

✔ Statistical Data Analysis
✔ Scientific Computing
✔ Data Processing
✔ Searching Large Arrays
✔ Competitive Programming
✔ Optimization Problems
✔ Performance-Critical Applications
✔ Numerical Computing

----------------------------------------------------------

Input

Enter number of elements:
6

Enter elements:
45 12 89 23 67 10

==========================================================
*/