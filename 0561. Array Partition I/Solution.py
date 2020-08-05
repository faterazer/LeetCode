from typing import List


class Solution:
    # Sort
    def arrayPairSum_MK1(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])

    # Hash
    def arrayPairSum_MK2(self, nums: List[int]) -> int:
        hash_table = [0] * 20001
        for num in nums:
            hash_table[num + 10000] += 1
        d, ret = 0, 0
        for i in range(len(hash_table)):
            if (hash_table[i]):
                ret += (hash_table[i] - d + 1) // 2 * (i - 10000)
                d = (hash_table[i] - d) % 2
        return ret
