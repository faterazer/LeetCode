from typing import List


class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        ans = 0
        cnt = [0] * 24
        for h in hours:
            ans += cnt[(24 - h % 24) % 24]
            cnt[h % 24] += 1
        return ans
