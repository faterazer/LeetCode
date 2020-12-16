from typing import List


class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        ret = []
        i = j = 0
        while j < len(s):
            while j < len(s) and s[j] == s[i]:
                j += 1
            if j - i >= 3:
                ret.append([i, j - 1])
            i = j
        return ret
