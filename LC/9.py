class Solution(object):
    def moveZeroes(self, nums):
        iterator = 0
        for num in nums:
            if num!=0:
                nums[iterator]=num
                iterator+=1
        while iterator<len(nums):
            nums[iterator]=0
            iterator+=1