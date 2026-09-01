/*
209. Minimum Size Subarray Sum
Medium
Topics
premium lock icon
Companies
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int left=0;
//         int sum=0;
//         int minlen=0;
//         int n=0;
//         int minest=9999999999;
//         for(int right=0;right<nums.size();right++){
//             sum+=nums[right];
//             if(sum>target){
//                 sum-=nums[left];
//                 left++;
//                 if(sum==target){
//                     n=right-left+1;
//                     minlen = n;
//                 }

//             }else if(sum==target){
//                 minlen = right-left+1;
//             }
//         minest=min(minest,minlen);
//         }
//         return minest;

//     }
// };

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int sum = 0;
        int minlen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {

            // Expand window
            sum += nums[right];

            // Shrink while window is valid
            while (sum >= target) {

                minlen = min(minlen, right - left + 1);

                sum -= nums[left];
                left++;
            }
        }

        // No valid subarray found
        if (minlen == INT_MAX)
            return 0;

        return minlen;
    }
};