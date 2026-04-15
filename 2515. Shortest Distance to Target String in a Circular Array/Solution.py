class Solution:
    def closestTarget(self, words: list[str], target: str, startIndex: int) -> int:
        n = len(words)
        for k in range(n // 2 + 1):
            if words[(startIndex - k) % n] == target or words[(startIndex + k) % n] == target:
                return k
        return -1
