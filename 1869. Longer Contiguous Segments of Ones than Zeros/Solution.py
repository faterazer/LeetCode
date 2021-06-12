class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        return len(max(s.split('0'))) > len(max(s.split('1')))
