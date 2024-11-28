from typing import List


class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        ans = cnt = 0
        for i in range(1, n + k - 1):
            if colors[(i - 1) % n] == colors[i % n]:
                cnt = 0
            else:
                cnt += 1
            ans += cnt >= k - 1
        return ans
