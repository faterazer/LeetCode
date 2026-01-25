from collections import Counter, defaultdict


class Solution:
    def countPairs(self, words: list[str]) -> int:
        result = 0
        cnt = defaultdict(int)
        for s, c in Counter(words).items():
            t = list(s)
            base = ord(t[0])
            for i, ch in enumerate(t):
                t[i] = chr((ord(ch) - base) % 26)
            t = "".join(t)
            result += cnt[t] * c + c * (c - 1) // 2
            cnt[t] += c
        return result
