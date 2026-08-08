#include <stdio.h>
#include <string.h>

int characterReplacement(char* s, int k) {
    int freq[26] = {0};

    int left = 0;
    int maxFreq = 0;
    int ans = 0;
    int n = strlen(s);

    for (int right = 0; right < n; right++) {

        // Add current character
        freq[s[right] - 'A']++;

        // Update the highest frequency in the window
        if (freq[s[right] - 'A'] > maxFreq)
            maxFreq = freq[s[right] - 'A'];

        // If replacements needed > k, shrink window
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        // Update answer
        int windowSize = right - left + 1;
        if (windowSize > ans)
            ans = windowSize;
    }

    return ans;
}