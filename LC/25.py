class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # Sum of the first window
        window_sum = sum(nums[:k])
        max_sum = window_sum

        # Slide the window
        for i in range(k, len(nums)):
            window_sum += nums[i]      # Add new element
            window_sum -= nums[i - k]  # Remove old element

            max_sum = max(max_sum, window_sum)

        return max_sum / k