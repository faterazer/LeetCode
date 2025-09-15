class Solution:
    def maxBalancedShipments(self, weight: list[int]) -> int:
        ans, i, n = 0, 1, len(weight)
        while i < n:
            if weight[i] < weight[i - 1]:
                ans += 1
                i += 1
            i += 1
        return ans
