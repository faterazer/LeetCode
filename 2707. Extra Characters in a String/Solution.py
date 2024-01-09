from typing import List


class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        dictionary = set(dictionary)
        dp = [0] * (len(s) + 1)
        for i in range(len(s)):
            dp[i + 1] = dp[i] + 1
            for word in dictionary:
                if s[: i + 1].endswith(word):
                    dp[i + 1] = min(dp[i + 1], dp[i + 1 - len(word)])
        return dp[-1]
