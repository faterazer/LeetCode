class Solution:
    def mergeAdjacent(self, nums: list[int]) -> list[int]:
        result = []
        for x in nums:
            while result and result[-1] == x:
                result.pop()
                x *= 2
            result.append(x)
        return result
