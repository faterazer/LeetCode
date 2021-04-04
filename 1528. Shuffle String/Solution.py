from typing import List


class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        res = [''] * len(s)
        for i, c in enumerate(s):
            res[indices[i]] = c;
        return ''.join(res)
