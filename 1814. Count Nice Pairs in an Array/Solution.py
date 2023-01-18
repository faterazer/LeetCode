from collections import defaultdict
from typing import List


class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        res, MOD = 0, 10**9 + 7
        cnt = defaultdict(int)
        for e in nums:
            x = e - int(str(e)[::-1])
            res = (res + cnt[x]) % MOD
            cnt[x] += 1
        return res
