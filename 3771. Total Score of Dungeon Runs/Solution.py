import bisect


class Solution:
    def totalScore(self, hp: int, damage: list[int], requirement: list[int]) -> int:
        result = 0
        damage_accum = [0] * (len(damage) + 1)
        for i, (d, r) in enumerate(zip(damage, requirement)):
            damage_accum[i + 1] = damage_accum[i] + d
            need = r - hp + damage_accum[i + 1]
            idx = bisect.bisect_left(damage_accum, need, 0, i + 1)
            result += i + 1 - idx
        return result
