from typing import List


class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        cnt = [[0] * 11 for _ in range(n)]
        for player, color in pick:
            cnt[player][color] += 1

        return sum(max(row) > i for i, row in enumerate(cnt))
