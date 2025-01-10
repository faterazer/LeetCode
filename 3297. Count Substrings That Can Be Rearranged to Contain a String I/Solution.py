from collections import defaultdict


class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        if len(word1) < len(word2):
            return 0

        diff = defaultdict(int)
        for c in word2:
            diff[c] += 1
        less = len(diff)

        i = ans = 0
        for j, c in enumerate(word1):
            diff[c] -= 1
            less -= diff[c] == 0
            if less > 0:
                continue

            while less == 0:
                ans += len(word1) - j
                if diff[word1[i]] == 0:
                    less += 1
                diff[word1[i]] += 1
                i += 1
        return ans
