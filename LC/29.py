class Solution:
    def longestCommonPrefix(self,arr:list[str])->str:
        for i in range(len(arr[0])):
            for j in range(1,len(arr)):
                if i>=len(arr[j]) or arr[j][i]!=arr[0][i]:
                    return arr[0][0:i]
                   
        return arr[0]

