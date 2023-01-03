class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        prev = 0
        for token in s.split():
            if token.isdigit():
                if (cur := int(token)) <= prev:
                    return False
                prev = cur
        return True
