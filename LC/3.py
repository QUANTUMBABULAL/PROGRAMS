class Solution(object):
    def twoSum(self, nums, target):

        hashmap = {}

        for i in range(len(nums)):

            num = nums[i]

            complement = target - num

            if complement in hashmap:
                return [hashmap[complement], i]

            hashmap[num] = i