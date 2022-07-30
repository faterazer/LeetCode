from typing import Counter, List


class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        cnt = {}
        for word in words2:
            c = Counter(word)
            for k, v in c.items():
                cnt[k] = max(cnt.get(k, 0), v)

        res = []
        for word in words1:
            c = Counter(word)
            if all(c.get(k, 0) >= v for k, v in cnt.items()):
                res.append(word)
        return res
