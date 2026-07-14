#include <stdio.h>
#include <time.h>

/*
==========================================================
                Quick Sort Algorithm
==========================================================

Approach Used:
- Divide and Conquer
- Recursion

Idea:
- Select a Pivot element (here, the last element).
- Rearrange the array so that:
    • Elements smaller than the pivot come before it.
    • Elements larger than the pivot come after it.
- The pivot reaches its correct sorted position.
- Recursively apply the same process to the left and
  right subarrays.

Note:
- Quick Sort is an In-Place Sorting Algorithm.
- It is NOT a Stable Sorting Algorithm.
- It is one of the fastest sorting algorithms in practice.

Applications:
- Large Dataset Sorting
- Database Systems
- Competitive Programming
- Searching Algorithms
- Operating Systems
- Standard Library Sorting

==========================================================
*/

//----------------------------------------------------------
// Function : swap()
// Purpose  : Swaps two elements.
//----------------------------------------------------------
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//----------------------------------------------------------
// Function : partition()
// Purpose  : Places the pivot element at its correct
//            position and arranges elements.
//
// Pivot Used:
// Last element of the array.
//
// Returns:
// Final position of the pivot.
//----------------------------------------------------------
int partition(int arr[], int low, int high)
{
    // Choose last element as pivot
    int pivot = arr[high];

    // Index of smaller element
    int i = low - 1;

    // Compare every element with pivot
    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;

            // Place smaller element before pivot
            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot in its correct position
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

//----------------------------------------------------------
// Function : quickSort()
// Purpose  : Sorts the array using Quick Sort.
//
// Divide:
// Partition the array.
//
// Conquer:
// Recursively sort left and right subarrays.
//----------------------------------------------------------
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        // Partition Index
        int pi = partition(arr, low, high);

        // Sort Left Half
        quickSort(arr, low, pi - 1);

        // Sort Right Half
        quickSort(arr, pi + 1, high);
    }
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

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    //------------------------------------------------------
    // End Execution Time
    //------------------------------------------------------
    clock_t end = clock();

    // Calculate Execution Time
    double time_taken =
    ((double)(end - start)) / CLOCKS_PER_SEC;

    //------------------------------------------------------
    // Display Sorted Array
    //------------------------------------------------------
    printf("\nSorted Array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nExecution Time : %f seconds\n",
           time_taken);

    return 0;
}

/*
==========================================================
Time Complexity

Best Case    : O(N log N)
Average Case : O(N log N)
Worst Case   : O(N²)

Reason:
- Best/Average Case:
  Pivot divides the array into nearly equal halves.

- Worst Case:
  Pivot is always the smallest or largest element,
  creating highly unbalanced partitions.

----------------------------------------------------------

Space Complexity

Best/Average Case : O(log N)
Worst Case        : O(N)

Reason:
- Space is used only by the recursion stack.
- Worst case occurs when partitions are highly
  unbalanced.

----------------------------------------------------------

Technique Used:
✔ Divide and Conquer
✔ Recursion
✔ In-Place Sorting

----------------------------------------------------------

Where is it Used?

✔ Database Systems
✔ Large Dataset Sorting
✔ Competitive Programming
✔ Operating Systems
✔ Standard Library Sorting Functions
✔ Search Optimization
✔ Data Processing
✔ Real-Time Applications

----------------------------------------------------------

Input

Enter number of elements:
6

Enter elements:
38 27 43 3 9 82

==========================================================
*/