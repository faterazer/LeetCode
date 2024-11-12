class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        i = ans = 0
        cnt = [0, 0]
        for j, c in enumerate(s):
            cnt[ord(c) & 1] += 1
            while cnt[0] > k and cnt[1] > k:
                cnt[ord(s[i]) & 1] -= 1
                i += 1
            ans += j - i + 1
        return ans
