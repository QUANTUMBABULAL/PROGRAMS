#include <stdio.h>
#include <time.h>

#define MAX 100  // adjust based on max possible value

int main()
{
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int B[] = {4, 7, 9, 12, 15, 20};

    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    int hash[MAX] = {0}; // hash table

    // Start time
    clock_t start = clock();

    // Insert elements of A into hash
    for (int i = 0; i < n; i++)
    {
        hash[A[i]] = 1;
    }

    int count = 0;

    printf("Sorted Array A: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");

    printf("Unsorted Array B: ");
    for (int i = 0; i < m; i++)
        printf("%d ", B[i]);

    printf("\n");

    printf("Common Elements: ");

    // Check common elements
    for (int i = 0; i < m; i++)
    {
        if (hash[B[i]] == 1)
        {
            printf("%d ", B[i]);
            count++;
        }
    }

    // End time
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nNumber of common elements = %d\n", count);
    printf("Execution Time = %f seconds\n", time_taken);

    return 0;
}