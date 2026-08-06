/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
 


*/
#include <stdbool.h>
bool checkInclusion(char* s1, char* s2) {
    int right =0;
    int left =0;
    int freq[10001]={0};
    int n=strlen(s1);
    int m=strlen(s2);
    for(int i=0;i<n;i++){
        freq[s1[i]]++;
    }
    int freq1[10001]={0};
    while(right<m){
        freq1[s2[right]]++;
        bool same =true;
        if(right-left+1==n){
            for(int i=0;i<10001;i++){
                    if(freq[i]!=freq1[i]){
                        same=false;
                    }          
                }
            if(same==true){
                return true;
            }
            freq1[s2[left]]--;
            left++;
            }
        
        right++;
    }
    return false;

    }

