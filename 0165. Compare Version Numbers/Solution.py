from itertools import zip_longest


class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1, v2 = map(int, version1.split(".")), map(int, version2.split("."))
        for a, b in zip_longest(v1, v2, fillvalue=0):
            if a != b:
                return -1 if a < b else 1
        return 0
