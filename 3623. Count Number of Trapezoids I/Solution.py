from collections import Counter


class Solution:
    def countTrapezoids(self, points: list[list[int]]) -> int:
        MOD = 10**9 + 7
        y_count = Counter(y for _, y in points)
        result, comb_accum = 0, 0
        for count in y_count.values():
            if count < 2:
                continue
            comb = count * (count - 1) // 2 % MOD
            result = (result + comb_accum * comb) % MOD
            comb_accum = (comb_accum + comb) % MOD
        return result
