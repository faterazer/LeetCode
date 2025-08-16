from itertools import zip_longest


class Solution:
    def printVertically(self, s: str) -> list[str]:
        return ["".join(x).rstrip() for x in zip_longest(*s.split(), fillvalue=" ")]
