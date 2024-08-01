from typing import List


class Solution:
    # 枚举中间点。时间复杂度：O(n^2)，空间复杂度：O(1)
    def numTeams_MK1(self, rating: List[int]) -> int:
        n, res = len(rating), 0
        for j in range(n):
            iless = imore = kless = kmore = 0
            for i in range(j):
                if rating[i] < rating[j]:
                    iless += 1
                elif rating[i] > rating[j]:
                    imore += 1
            for k in range(n - 1, j, -1):
                if rating[k] < rating[j]:
                    kless += 1
                elif rating[k] > rating[j]:
                    kmore += 1
            res += iless * kmore + imore * kless
        return res

    # 使用树状数组（Binary Indexed Tree）。时间复杂度：O(nlgn)，空间复杂度：O(n)
    def numTeams_MK2(self, rating: List[int]) -> int:
        def updateBIT(BIT: List[int], index: int, val: int) -> None:
            while index < len(BIT):
                BIT[index] += val
                index += index & (-index)

        def getPrefixSum(BIT: List[int], index: int) -> int:
            res = 0
            while index > 0:
                res += BIT[index]
                index -= index & (-index)
            return res

        max_rating = max(rating)
        left_BIT, right_BIT = [0] * (max_rating + 1), [0] * (max_rating + 1)

        for x in rating:
            updateBIT(right_BIT, x, 1)

        res = 0
        for x in rating:
            updateBIT(right_BIT, x, -1)
            left_less = getPrefixSum(left_BIT, x - 1)
            left_more = getPrefixSum(left_BIT, max_rating) - getPrefixSum(left_BIT, x)
            right_less = getPrefixSum(right_BIT, x - 1)
            right_more = getPrefixSum(right_BIT, max_rating) - getPrefixSum(right_BIT, x)
            updateBIT(left_BIT, x, 1)

            res += left_less * right_more + left_more * right_less
        return res
