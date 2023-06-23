from typing import List


class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        return max(int(s) if s.isdigit() else len(s) for s in strs)
