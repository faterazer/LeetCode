class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken = set(brokenLetters)
        res, hasBroken = 0, 1
        for c in text:
            if c == ' ':
                res += hasBroken
                hasBroken = 1
            elif c in broken:
                hasBroken = 0
        return res + hasBroken
