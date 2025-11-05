from collections import defaultdict

from sortedcontainers import SortedList


class Solution:
    def findXSum(self, nums: list[int], k: int, x: int) -> list[int]:
        cnt = defaultdict(int)
        L = SortedList()
        R = SortedList()
        x_sum = 0

        def add(val: int) -> None:
            if cnt[val] == 0:
                return
            p = (cnt[val], val)
            if L and p > L[0]:
                L.add(p)
                nonlocal x_sum
                x_sum += p[0] * p[1]
            else:
                R.add(p)

        def remove(val: int) -> None:
            if cnt[val] == 0:
                return
            p = (cnt[val], val)
            if p in L:
                L.remove(p)
                nonlocal x_sum
                x_sum -= p[0] * p[1]
            else:
                R.remove(p)

        def L2R() -> None:
            p = L.pop(0)
            R.add(p)
            nonlocal x_sum
            x_sum -= p[0] * p[1]

        def R2L() -> None:
            p = R.pop()
            L.add(p)
            nonlocal x_sum
            x_sum += p[0] * p[1]

        ans = [0] * (len(nums) - k + 1)
        for r, num in enumerate(nums):
            remove(num)
            cnt[num] += 1
            add(num)

            l = r + 1 - k
            if l < 0:
                continue

            while len(L) > x:
                L2R()
            while R and len(L) < x:
                R2L()
            ans[l] = x_sum

            num = nums[l]
            remove(num)
            cnt[num] -= 1
            add(num)
        return ans
