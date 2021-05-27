class Solution:
    def checkOnesSegment_MK1(self, s: str) -> bool:
        return '01' not in s

    def checkOnesSegment_MK2(self, s: str) -> bool:
        return sum(a != b for a, b in zip(s, s[1:])) < 2
