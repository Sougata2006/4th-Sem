#include <stdio.h>
#include <time.h>

/*
==========================================================
            Binary Search using Recursion
==========================================================

Approach Used:
- Divide and Conquer
- Recursion

Idea:
- Binary Search works only on a SORTED array.
- Find the middle element.
- If the key is equal to the middle element, return its index.
- If the key is smaller, search the left half.
- Otherwise, search the right half.
- Repeat until the element is found or the search space becomes empty.

Applications:
- Searching in Sorted Arrays
- Database Indexing
- Dictionary Search
- Library Management Systems
- Searching Large Sorted Data
- Competitive Programming

==========================================================
*/

//----------------------------------------------------------
// Function : binarySearch()
// Purpose  : Searches an element using Recursive
//            Binary Search.
//
// Parameters:
// arr[]  -> Sorted Array
// left   -> Starting Index
// right  -> Ending Index
// key    -> Element to Search
//
// Returns:
// Index of the element if found
// -1 if element is not present
//----------------------------------------------------------
int binarySearch(int arr[], int left, int right, int key)
{
    // Continue searching while search space exists
    if(left <= right)
    {
        // Find middle index
        int mid = left + (right - left) / 2;

        // If key is found at middle
        if(arr[mid] == key)
            return mid;

        // If key is smaller than middle element,
        // search left half
        if(arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);

        // Otherwise search right half
        return binarySearch(arr, mid + 1, right, key);
    }

    // Element not found
    return -1;
}

//----------------------------------------------------------
// Main Function
//----------------------------------------------------------
int main()
{
    int n, key, i;

    //------------------------------------------------------
    // Input number of elements
    //------------------------------------------------------
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Declare array
    int arr[n];

    //------------------------------------------------------
    // Input sorted array
    //------------------------------------------------------
    printf("Enter sorted elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    //------------------------------------------------------
    // Input element to search
    //------------------------------------------------------
    printf("Enter element to search: ");
    scanf("%d", &key);

    //------------------------------------------------------
    // Start Execution Time
    //------------------------------------------------------
    clock_t start = clock();

    // Perform Binary Search
    int result = binarySearch(arr, 0, n - 1, key);

    //------------------------------------------------------
    // End Execution Time
    //------------------------------------------------------
    clock_t end = clock();

    // Calculate total execution time
    double time_taken =
    ((double)(end - start)) / CLOCKS_PER_SEC;

    //------------------------------------------------------
    // Display Result
    //------------------------------------------------------
    if(result != -1)
        printf("\nElement found at index %d\n", result);
    else
        printf("\nElement not found\n");

    // Display execution time
    printf("Execution Time : %f seconds\n", time_taken);

    return 0;
}

/*
==========================================================
Time Complexity : O(log N)

Reason:
- In every recursive call, the search space is divided
  into two equal halves.
- Therefore, the number of comparisons reduces
  logarithmically.

Best Case    : O(1)
Average Case : O(log N)
Worst Case   : O(log N)

----------------------------------------------------------

Space Complexity : O(log N)

Reason:
- Recursive Binary Search uses recursion stack.
- Maximum recursion depth is log N.

(Iterative Binary Search uses O(1) space.)

----------------------------------------------------------

Technique Used:
✔ Divide and Conquer
✔ Recursion
✔ Binary Search

----------------------------------------------------------

Where is it Used?

✔ Searching in Sorted Arrays
✔ Database Indexing
✔ Dictionary Search
✔ Phone Contact Search
✔ Library Management Systems
✔ Competitive Programming
✔ Large Sorted Data Searching

----------------------------------------------------------

Input

Enter number of elements:
6

Enter sorted elements:
10 20 30 40 50 60

Enter element to search:
40

==========================================================
*/