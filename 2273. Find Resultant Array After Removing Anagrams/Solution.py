from collections import Counter


class Solution:
    def removeAnagrams(self, words: list[str]) -> list[str]:
        ans = []
        cnt1 = Counter()
        for word in words:
            cnt2 = Counter(word)
            if cnt1 != cnt2:
                ans.append(word)
                cnt1 = cnt2
        return ans
