from itertools import pairwise


class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        seen = set()
        for x, y in pairwise(s):
            seen.add(x + y)
            if y + x in seen:
                return True
        return False
