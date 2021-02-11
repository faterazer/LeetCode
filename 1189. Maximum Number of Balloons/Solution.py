import collections


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        count = collections.Counter(text)
        countBallon = collections.Counter("balloon")
        return min(count[ch] // countBallon[ch] for ch in countBallon)
