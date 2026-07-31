class Solution:
    def duplicate(self,arr:list[int])->list[int]:
        freq={}
        for num in arr:
            if num in freq:
                freq[num]+=1
            else:
                freq[num]=1

        duplicate =[]
        for key,value in freq.items():
            if value>1:
                duplicate.append(key)

        return duplicate

obj = Solution()
arr=input()
        