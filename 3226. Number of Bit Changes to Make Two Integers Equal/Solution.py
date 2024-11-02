class Solution:
    def minChanges(self, n: int, k: int) -> int:
        return -1 if (n | k) != n else (n ^ k).bit_count()
