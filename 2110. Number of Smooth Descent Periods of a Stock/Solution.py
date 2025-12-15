class Solution:
    def getDescentPeriods(self, prices: list[int]) -> int:
        result = dec = 0
        for i, p in enumerate(prices):
            if i > 0 and prices[i] == prices[i - 1] - 1:
                dec += 1
            else:
                dec = 1
            result += dec
        return result
