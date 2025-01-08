from typing import List


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        ans = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                ans += words[j].startswith(words[i]) and words[j].endswith(words[i])
        return ans
