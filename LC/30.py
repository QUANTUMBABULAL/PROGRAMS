def palindrome(s):
    new = ""
    for ch in s:
        if ch.isalnum():
            new += ch
    new = new.lower()
    if new == new[::-1]:
        return True
s = str(input())
result = palindrome(s)
print(result)