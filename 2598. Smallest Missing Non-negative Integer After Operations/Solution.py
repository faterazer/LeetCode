from collections import Counter


class Solution:
    def findSmallestInteger(self, nums: list[int], value: int) -> int:
        cnt = Counter(x % value for x in nums)
        ans = 0
        while cnt[ans % value] > 0:
            cnt[ans % value] -= 1
            ans += 1
        return ans
