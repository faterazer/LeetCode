class Solution:
    def countInterestingSubarrays(self, nums: list[int], modulo: int, k: int) -> int:
        cnt = [0] * min(len(nums) + 1, modulo)
        cnt[0] = 1
        ans = s = 0
        for x in nums:
            s += x % modulo == k
            if s >= k:
                ans += cnt[(s - k) % modulo]
            cnt[s % modulo] += 1
        return ans
