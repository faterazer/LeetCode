from collections import Counter


class Solution:
    def balancedString(self, s: str) -> int:
        cnt = Counter(s)
        res, limit, i = len(s), len(s) // 4, 0
        if cnt["Q"] == cnt["W"] == cnt["E"] == cnt["R"]:
            return 0
        if all(cnt[c] == limit for c in "QWER"):
            return 0
        for j, c in enumerate(s):
            cnt[c] -= 1
            while all(cnt[c] <= limit for c in "QWER"):
                res = min(res, j - i + 1)
                cnt[s[i]] += 1
                i += 1
        return res
