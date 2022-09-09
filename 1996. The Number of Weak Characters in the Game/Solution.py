from typing import List


class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        max_def = res = 0
        for _, defense in sorted(properties, key=lambda x: (-x[0], x[1])):
            if defense < max_def:
                res += 1
            else:
                max_def = defense
        return res
