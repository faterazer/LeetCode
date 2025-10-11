from collections import Counter


class Solution:
    def maximumTotalDamage(self, power: list[int]) -> int:
        cnt = Counter(power)
        cnt[0] = 0
        f = sorted(map(list, cnt.items()))

        j = 0
        for i in range(1, len(f)):
            while f[j + 1][0] + 2 < f[i][0]:
                j += 1
            f[i][1] = max(f[i - 1][1], f[j][1] + f[i][0] * f[i][1])
        return f[-1][1]
