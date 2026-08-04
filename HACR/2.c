#include <stdio.h>
#include <stdlib.h>

int maximumDistinctSubarraySum(int arr_count, int* arr, int k)
{
    if (k > arr_count)
        return 0;

    int freq[100001] = {0};   // Frequency of each value
    int duplicate = 0;        // Number of values appearing more than once
    int sum = 0;
    int maxSum = 0;

    int left = 0;
    int right = 0;

    while (right < arr_count)
    {
        // Add current element into the window
        sum += arr[right];
        freq[arr[right]]++;

        // If frequency becomes 2, we found a duplicate
        if (freq[arr[right]] == 2)
            duplicate++;

        // Window size reached k
        if (right - left + 1 == k)
        {
            // Valid window
            if (duplicate == 0)
            {
                if (sum > maxSum)
                    maxSum = sum;
            }

            // Remove left element before sliding
            freq[arr[left]]--;

            // If frequency changes from 2 -> 1,
            // one duplicate disappears
            if (freq[arr[left]] == 1)
                duplicate--;

            sum -= arr[left];
            left++;
        }

        right++;
    }

    return maxSum;
}

int main()
{
    int arr_count;
    scanf("%d", &arr_count);

    int *arr = (int *)malloc(arr_count * sizeof(int));

    for (int i = 0; i < arr_count; i++)
        scanf("%d", &arr[i]);

    int k;
    scanf("%d", &k);

    printf("%d\n", maximumDistinctSubarraySum(arr_count, arr, k));

    free(arr);
    return 0;
}