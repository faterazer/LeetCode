class Solution:
    def kLengthApart(self, nums: list[int], k: int) -> bool:
        gap = k
        for x in nums:
            if x:
                if gap < k:
                    return False
                gap = 0
            else:
                gap += 1
        return True
