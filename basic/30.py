class Solution:
    def isPalindrome(self, s: str) -> bool:
        new =""
        for ch in s: 
            if ch.isalnum():
                new+=ch.lower()
        if new == new[::-1]:
            return True 
        else:
            return False

        