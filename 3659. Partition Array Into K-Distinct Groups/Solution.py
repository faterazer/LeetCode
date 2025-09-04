from collections import defaultdict


class Solution:
    def partitionArray(self, nums: list[int], k: int) -> bool:
        nums_len = len(nums)
        if nums_len % k != 0:
            return False
        groups = nums_len // k
        cnt = defaultdict(int)
        for x in nums:
            cnt[x] += 1
            if cnt[x] > groups:
                return False
        return True
