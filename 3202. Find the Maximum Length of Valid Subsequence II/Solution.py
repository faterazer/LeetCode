class Solution:
    def maximumLength(self, nums: list[int], k: int) -> int:
        ans = 0
        for i in range(k):
            f = [0] * k
            for x in nums:
                x %= k
                f[x] = f[(i - x) % k] + 1
            ans = max(ans, max(f))
        return ans
