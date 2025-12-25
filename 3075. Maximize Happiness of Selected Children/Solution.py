class Solution:
    def maximumHappinessSum(self, happiness: list[int], k: int) -> int:
        happiness.sort(reverse=True)
        result = 0
        for i, x in enumerate(happiness):
            if i >= k or x <= i:
                break
            result += x - i
        return result
