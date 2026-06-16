class Solution(object):
    def majorityElement(self, nums):
        freq = {} 
        target = len(nums)//2;
        for num in nums : 
            freq[num]=freq.get(num,0)+1
        for num in nums:
            if( freq[num]>target):
                return num 