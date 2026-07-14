#include <stdio.h>
#include <time.h>

/*
==========================================================
                Merge Sort Algorithm
==========================================================

Approach Used:
- Divide and Conquer
- Recursion

Idea:
- Divide the array into two equal halves.
- Recursively sort both halves.
- Merge the two sorted halves into one sorted array.
- Continue until the entire array becomes sorted.

Note:
- Merge Sort is a Stable Sorting Algorithm.
- It guarantees O(N log N) time complexity in all cases.
- Suitable for large datasets.

Applications:
- External Sorting
- Database Systems
- Sorting Linked Lists
- Large Data Processing
- File Sorting
- Parallel Computing

==========================================================
*/

//----------------------------------------------------------
// Function : merge()
// Purpose  : Merges two sorted subarrays into a single
//            sorted array.
//
// First Subarray  : arr[left ... mid]
// Second Subarray : arr[mid+1 ... right]
//----------------------------------------------------------
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;

    // Size of left and right subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int L[n1], R[n2];

    //------------------------------------------------------
    // Copy elements into temporary arrays
    //------------------------------------------------------
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    //------------------------------------------------------
    // Merge both sorted arrays
    //------------------------------------------------------
    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    //------------------------------------------------------
    // Copy remaining elements of Left Array
    //------------------------------------------------------
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    //------------------------------------------------------
    // Copy remaining elements of Right Array
    //------------------------------------------------------
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//----------------------------------------------------------
// Function : mergeSort()
// Purpose  : Sorts the array using Merge Sort.
//
// Divide:
// Split the array into two halves.
//
// Conquer:
// Recursively sort both halves.
//
// Combine:
// Merge the sorted halves.
//----------------------------------------------------------
void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        // Find middle index
        int mid = left + (right - left) / 2;

        // Sort Left Half
        mergeSort(arr, left, mid);

        // Sort Right Half
        mergeSort(arr, mid + 1, right);

        // Merge both sorted halves
        merge(arr, left, mid, right);
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

    // Perform Merge Sort
    mergeSort(arr, 0, n - 1);

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
Worst Case   : O(N log N)

Reason:
- The array is divided into log N levels.
- At each level, merging takes O(N).

Overall:
O(N log N)

----------------------------------------------------------

Space Complexity : O(N)

Reason:
- Temporary arrays are used during merging.

----------------------------------------------------------

Technique Used:
✔ Divide and Conquer
✔ Recursion
✔ Stable Sorting

----------------------------------------------------------

Where is it Used?

✔ External Sorting
✔ Database Management Systems
✔ Linked List Sorting
✔ Large Dataset Sorting
✔ Parallel Computing
✔ File Sorting
✔ Big Data Processing
✔ Merge Operations in Algorithms

----------------------------------------------------------

Input

Enter number of elements:
6

Enter elements:
38 27 43 3 9 82

==========================================================
*/