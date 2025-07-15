class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False

        vowels = set("aeiouAEIOU")
        flag = 0
        for c in word:
            if c.isalpha():
                if c in vowels:
                    flag |= 1 << 1
                else:
                    flag |= 1 << 0
            elif not c.isdigit():
                return False
        return flag == 3
