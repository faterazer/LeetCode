from collections import Counter


class Solution:
    def divideArray(self, nums: list[int]) -> bool:
        cnt = Counter(nums)
        return all(c % 2 == 0 for c in cnt.values())
