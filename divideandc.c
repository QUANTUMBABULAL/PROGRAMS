#include <stdio.h>
#include <time.h>

// Binary Search Function
int binarySearch(int A[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (A[mid] == target)
            return 1; // found
        else if (A[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0; // not found
}

// Divide and Conquer Function
int countCommon(int A[], int n, int B[], int low, int high)
{
    if (low > high)
        return 0;

    if (low == high)
    {
        if (binarySearch(A, 0, n - 1, B[low]))
            return 1;
        else
            return 0;
    }

    int mid = low + (high - low) / 2;

    int leftCount = countCommon(A, n, B, low, mid);
    int rightCount = countCommon(A, n, B, mid + 1, high);

    return leftCount + rightCount;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int B[] = {4, 7, 9, 12, 15, 20};

    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    printf("Sorted Array A: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");

    printf("Unsorted Array B: ");
    for (int i = 0; i < m; i++)
        printf("%d ", B[i]);

    printf("\n");

    // Start time
    clock_t start = clock();

    int result = countCommon(A, n, B, 0, m - 1);

    // End time
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Number of common elements = %d\n", result);
    printf("Execution Time = %f seconds\n", time_taken);

    return 0;
}