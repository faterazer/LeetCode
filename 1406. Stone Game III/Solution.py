from typing import List


class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        f = [0] * (len(stoneValue) + 3)
        suf_sum = 0
        for i in range(len(stoneValue) - 1, -1, -1):
            suf_sum += stoneValue[i]
            f[i] = suf_sum - min(f[i + 1], f[i + 2], f[i + 3])
        if 2 * f[0] > suf_sum:
            return "Alice"
        elif 2 * f[0] < suf_sum:
            return "Bob"
        else:
            return "Tie"
