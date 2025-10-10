class Solution:
    def minArraySum(self, nums: list[int], k: int) -> int:
        min_f = [-1] * k
        min_f[0] = f = s = 0
        for x in nums:
            s = (s + x) % k
            f += x
            if min_f[s] != -1:
                f = min(f, min_f[s])
            min_f[s] = f
        return f
