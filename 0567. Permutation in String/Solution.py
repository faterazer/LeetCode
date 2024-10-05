from collections import Counter


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        cnt = Counter(s1)
        i = 0
        for j, c in enumerate(s2):
            cnt[c] -= 1
            while cnt[c] < 0:
                cnt[s2[i]] += 1
                i += 1
            if j - i + 1 == len(s1):
                return True
        return False
