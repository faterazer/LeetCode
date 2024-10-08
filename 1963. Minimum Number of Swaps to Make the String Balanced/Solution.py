class Solution:
    def minSwaps(self, s: str) -> int:
        cnt = 0
        for c in s:
            if c == "[":
                cnt += 1
            else:
                cnt = max(cnt - 1, 0)
        return (cnt + 1) // 2
