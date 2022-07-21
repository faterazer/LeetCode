import bisect
from collections import defaultdict, deque
from typing import Counter, List


class Solution:
    def numMatchingSubseq_MK1(self, s: str, words: List[str]) -> int:
        def isSubseq(s: str, word: str) -> bool:
            it = iter(s)
            return all(c in it for c in word)

        cnt = Counter(words)
        return sum(freq for word, freq in cnt.items() if isSubseq(s, word))

    def numMatchingSubseq_MK2(self, s: str, words: List[str]) -> int:
        indices = defaultdict(list)
        for i, e in enumerate(s):
            indices[e].append(i)
        cnt = Counter(words)
        res = 0
        for word, freq in cnt.items():
            idx, flag = -1, True
            for c in word:
                next_idx = bisect.bisect(indices[c], idx)
                if next_idx == len(indices[c]):
                    flag = False
                    break
                idx = indices[c][next_idx]
            if flag:
                res += freq
        return res

    def numMatchingSubseq_MK3(self, s: str, words: List[str]) -> int:
        dp = [[-1] * 26 for _ in range(len(s) + 1)]
        for i in range(len(dp) - 2, -1, -1):
            dp[i][:] = dp[i + 1]
            dp[i][ord(s[i]) - ord('a')] = i + 1
        res = 0
        cnt = Counter(words)
        for word, freq in cnt.items():
            idx = 0
            for c in word:
                idx = dp[idx][ord(c) - ord('a')]
                if (idx == -1):
                    break
            if idx != -1:
                res += freq
        return res

    def numMatchingSubseq_MK4(self, s: str, words: List[str]) -> int:
        buff = defaultdict(deque)
        cnt = Counter(words)
        for word in cnt.keys():
            buff[word[0]].append((word, 0))

        res = 0
        for c in s:
            dq = buff[c]
            n = len(dq)
            for _ in range(n):
                word, i = dq.popleft()
                if i + 1 == len(word):
                    res += cnt[word]
                else:
                    buff[word[i + 1]].append((word, i + 1))
        return res
