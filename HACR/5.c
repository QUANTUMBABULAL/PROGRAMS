// you are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000
 

// Constraints:

// n == nums.length
// 1 <= k <= n <= 105
// -104 <= nums[i] <= 104
 
double findMaxAverage(int* nums, int numsSize, int k) {
    double avg=0;
    double maxavg=-100000;
    int right=0;
    int left=0;
    // int freq[100001]={0};
  
    while(right<numsSize){

        avg+=(double)nums[right]/k;
        // freq[nums[right]]++;

        if(right-left+1==k){
            if(avg>maxavg){
                maxavg=avg;
            }
            avg-=(double)nums[left]/k;
            left++;
        }


        right++;

    }
    return maxavg;
}