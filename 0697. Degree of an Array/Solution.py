from typing import List


class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        hash_map = {}
        min_len, max_deg = 1, 0
        for i, n in enumerate(nums):
            if n not in hash_map:
                hash_map[n] = [0, i]
            hash_map[n][0] += 1
            if hash_map[n][0] > max_deg:
                max_deg += 1
                min_len = i - hash_map[n][1] + 1
            elif hash_map[n][0] == max_deg:
                min_len = min(min_len, i - hash_map[n][1] + 1)
        return min_len
