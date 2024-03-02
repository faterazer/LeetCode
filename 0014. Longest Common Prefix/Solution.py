from typing import List


class Solution:
    def longestCommonPrefix_MK1(self, strs: List[str]) -> str:
        '''
        Vertical scanning
        '''

        if not strs:
            return ""

        shortest = min(strs, key=len)
        for i, ch in enumerate(shortest):
            for s in strs:
                if s[i] != ch:
                    return shortest[:i]
        return shortest
