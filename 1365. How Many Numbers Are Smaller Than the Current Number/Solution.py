from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        hashMap = [0] * 101
        for num in nums:
            hashMap[num] += 1
        for i in range(1, len(hashMap)):
            hashMap[i] += hashMap[i - 1]
        return [hashMap[n - 1] if n else 0 for n in nums]
