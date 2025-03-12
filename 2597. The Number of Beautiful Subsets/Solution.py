from collections import Counter


class Solution:
    def beautifulSubsets(self, nums: list[int], k: int) -> int:
        cnt = Counter(nums)
        ans = 1
        for x, c in cnt.items():
            if x - k in cnt:
                continue
            f0, f1 = 1, 1 << c
            y = x + k
            while y in cnt:
                f0, f1 = f1, f0 * ((1 << cnt[y]) - 1) + f1
                y += k
            ans *= f1
        return ans - 1
