from typing import Counter, List


class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        res = length = 0
        for _, freq in cnt.most_common():
            length += freq
            res += 1
            if length * 2 >= len(arr):
                break
        return res
