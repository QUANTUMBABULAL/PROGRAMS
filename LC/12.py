from typing import List
from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Step 1: Count frequencies
        count = Counter(nums)
        
        # Step 2: Create buckets where index = frequency
        # We need len(nums) + 1 to account for the max possible frequency
        freq = [[] for _ in range(len(nums) + 1)]
        
        # Step 3: Populate the buckets
        for num, current_count in count.items():
            freq[current_count].append(num)
            
        # Step 4: Gather the top k elements by reading buckets backwards
        result = []
        for i in range(len(freq) - 1, -1, -1):
            for num in freq[i]:
                result.append(num)
                if len(result) == k:
                    return result
                    
        return result