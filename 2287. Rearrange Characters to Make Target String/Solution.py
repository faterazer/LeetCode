from collections import Counter


class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        cnt = Counter(s)
        return min(cnt[c] // freq for c, freq in Counter(target).items())
