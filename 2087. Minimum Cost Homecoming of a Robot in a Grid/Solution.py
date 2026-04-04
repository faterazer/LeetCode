class Solution:
    def minCost(self, startPos: list[int], homePos: list[int], rowCosts: list[int], colCosts: list[int]) -> int:
        r0, c0 = startPos
        r1, c1 = homePos
        result = -rowCosts[r0] - colCosts[c0]
        result += sum(rowCosts[min(r0, r1) : max(r0, r1) + 1])
        result += sum(colCosts[min(c0, c1) : max(c0, c1) + 1])
        return result
