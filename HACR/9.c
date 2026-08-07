#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {

    int freq[26] = {0};
    int freq1[26] = {0};

    int m = strlen(s);
    int n = strlen(p);

    int *arr = (int *)malloc(sizeof(int) * m);

    *returnSize = 0;

    if (n > m)
        return arr;

    // Frequency of p
    for (int i = 0; i < n; i++)
    {
        freq[p[i] - 'a']++;
    }

    int left = 0;

    for (int right = 0; right < m; right++)
    {
        // Add current character
        freq1[s[right] - 'a']++;

        // Shrink if window becomes larger than n
        if (right - left + 1 > n)
        {
            freq1[s[left] - 'a']--;
            left++;
        }

        // Window size is exactly n
        if (right - left + 1 == n)
        {
            bool same = true;

            for (int i = 0; i < 26; i++)
            {
                if (freq[i] != freq1[i])
                {
                    same = false;
                    break;
                }
            }

            if (same)
            {
                arr[*returnSize] = left;
                (*returnSize)++;
            }
        }
    }

    return arr;
}