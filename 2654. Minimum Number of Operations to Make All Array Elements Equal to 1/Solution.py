from math import gcd


class Solution:
    def minOperations_MK1(self, nums: list[int]) -> int:
        n = len(nums)
        gcd_all = cnt1 = 0
        for x in nums:
            gcd_all = gcd(gcd_all, x)
            cnt1 += x == 1
        if gcd_all > 1:
            return -1
        if cnt1:
            return n - cnt1

        min_size = n
        for i in range(n):
            g = 0
            for j in range(i, n):
                g = gcd(g, nums[j])
                if g == 1:
                    min_size = min(min_size, j - i)
                    break
        return min_size + n - 1

    def minOperations_MK2(self, nums: list[int]) -> int:
        n = len(nums)
        gcd_all = cnt1 = 0
        for x in nums:
            gcd_all = gcd(gcd_all, x)
            cnt1 += x == 1
        if gcd_all > 1:
            return -1
        if cnt1:
            return n - cnt1

        min_size = n
        g = []
        for i, x in enumerate(nums):
            g.append([x, i])

            j = 0
            for p in g:
                p[0] = gcd(p[0], x)
                if g[j][0] == p[0]:
                    g[j][1] = p[1]
                else:
                    j += 1
                    g[j] = p
            del g[j + 1 :]

            if g[0][0] == 1:
                min_size = min(min_size, i - g[0][1])
        return min_size + n - 1
