from collections import Counter


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return (Counter(t) - Counter(s)).popitem()[0]
