class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        if len(s) - k + 1 < (1 << k):
            return False
        n = int(s[:k], 2)
        seen = set([n])
        head_mask = ~(1 << (k - 1))
        for i in range(k, len(s)):
            n = (n & head_mask) << 1 | (ord(s[i]) - ord('0'))
            seen.add(n)
        return len(seen) == (1 << k)
