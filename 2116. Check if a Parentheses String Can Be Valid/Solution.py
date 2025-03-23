class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2 == 1:
            return False
        mn = mx = 0
        for c, lock in zip(s, locked):
            if lock == '1':
                d = 1 if c == '(' else -1
                mx += d
                if mx < 0:
                    return False
                mn += d
            else:
                mx += 1
                mn -= 1
            if mn < 0:
                mn = 1
        return mn == 0
